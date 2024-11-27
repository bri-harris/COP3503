#include <iostream>
#include<fstream>
#include<vector>
#include"extrafile.h"
using namespace std;

void ReadDataFromFile(vector<extrafile>& ships, int option) {
    if (option == 1) {
        ifstream inFile("friendlyships.shp", ios_base::binary);
        unsigned int count;
        inFile.read(reinterpret_cast<char *>(&count), sizeof(count));
        for (unsigned int i = 0; i < count; i++) {
            extrafile someShip;
            someShip.Deserialize(inFile);
            ships.push_back(someShip);
        }
    } else if (option == 2) {
        ifstream inFile("enemyships.shp", ios_base::binary);
        unsigned int count;
        inFile.read(reinterpret_cast<char *>(&count), sizeof(count));
        for (unsigned int i = 0; i < count; i++) {
            extrafile someShip;
            someShip.Deserialize(inFile);
            ships.push_back(someShip);
        }
    } else {
        ifstream inFile("friendlyships.shp", ios_base::binary);
        unsigned int count;
        inFile.read(reinterpret_cast<char *>(&count), sizeof(count));
        for (unsigned int i = 0; i < count; i++) {
            extrafile someShip;
            someShip.Deserialize(inFile);
            ships.push_back(someShip);
        }
        inFile.close();

        ifstream inFile2("enemyships.shp", ios_base::binary);
        unsigned int count2;
        inFile2.read(reinterpret_cast<char *>(&count2), sizeof(count2));
        for (unsigned int i = 0; i < count2; i++) {
            extrafile someShip;
            someShip.Deserialize(inFile2);
            ships.push_back(someShip);
        }
    }
}

void PrintAllShips(vector<extrafile>& ships) {
    for (unsigned int i = 0; i < ships.size(); i++) {
        ships[i].PrintShip();
    }
}

extrafile GetMostPowerfulWeapon(vector<extrafile>& ships) {
    extrafile weaponShip = ships[0];
    int powerRating1 = weaponShip.GetStrongestWeapon();
    int powerRating2 = 0;

    for (unsigned int i = 1; i < ships.size(); i++) {
        extrafile weaponShip2 = ships[i];
        powerRating2 = weaponShip2.GetStrongestWeapon();

        if (powerRating2 > powerRating1) {
            weaponShip = weaponShip2;
            powerRating1 = weaponShip.GetStrongestWeapon();
        }
    }
    return weaponShip;
}

extrafile GetMostPowerfulShip(vector<extrafile>& ships) {
    extrafile weaponShip = ships[0];
    int firepower1 = weaponShip.GetFirepower();
    int firepower2 = 0;

    for (unsigned int i = 1; i < ships.size(); i++) {
        extrafile weaponShip2 = ships[i];
        firepower2 = weaponShip2.GetFirepower();

        if (firepower2 > firepower1) {
            weaponShip = weaponShip2;
            firepower1 = weaponShip.GetFirepower();
        }
    }
    return weaponShip;
}

vector<extrafile> GetUnarmedShips(vector<extrafile>& ships) {
    vector<extrafile> unarmed;
    for (unsigned int i = 0; i < ships.size(); i++) {
        if (ships[i].GetFirepower() == 0) {
            unarmed.push_back(ships[i]);
        }
    }
    return unarmed;
}

vector<extrafile> GetArmedShips(vector<extrafile>& ships) {
    vector<extrafile> armed;
    for (unsigned int i = 0; i < ships.size(); i++) {
        if (ships[i].GetFirepower() != 0) {
            armed.push_back(ships[i]);
        }
    }
    return armed;
}

extrafile GetWeakestShip(vector<extrafile>& ships) {
    vector<extrafile> armed = GetArmedShips(ships);

    extrafile weakShip = armed[0];
    int firepower1 = weakShip.GetFirepower();
    int firepower2;

    for (unsigned int i = 1; i < armed.size(); i++) {
        extrafile weakShip2 = armed[i];
        firepower2 = weakShip2.GetFirepower();

        if (firepower2 < firepower1) {
            weakShip = weakShip2;
            firepower1 = weakShip.GetFirepower();
        }
    }
    return weakShip;
}


int main() {
    vector<extrafile> ships;
    ReadDataFromFile(ships, 3);

    // PrintAllShips(ships);
    // cout << "total ships: " << ships.size() << endl;

    // extrafile powerfulWeapon = GetMostPowerfulWeapon(ships);
    // powerfulWeapon.PrintShip();

    // extrafile powerfulShip = GetMostPowerfulShip(ships);
    // powerfulShip.PrintShip();

    // extrafile weakShip = GetWeakestShip(ships);
    // weakShip.PrintShip();

    // vector<extrafile> unarmed = GetUnarmedShips(ships);
    // PrintAllShips(unarmed);

    return 0;
}


// /*---------------------------------load data into program-------------------------------------------------*/
// // ifstream inFile("enemyships.shp", ios_base::binary);
// ifstream inFile("friendlyships.shp", ios_base::binary);
//
// unsigned int count;
// inFile.read(reinterpret_cast<char *>(&count), sizeof(count));
// // cout << "count: " << count << endl;
//
// for (unsigned i = 0; i < count; i++) {
//     /*--------------------------------------read in NAME String-----------------------------------------------------*/
//     unsigned int length;
//     inFile.read(reinterpret_cast<char *>(&length), sizeof(length));
//     // cout << "length: " << length << endl;
//
//     //dynamically allocate an array of chars exactly the right size
//     //make a temporary character pointer
//     char* tempArr = new char[length];
//     inFile.read(tempArr, length);
//
//     //store in our string var, then delete the temp char *
//     string name = tempArr;
//     delete[] tempArr;
//     cout << "Name: " << name << endl;
//
//     /*--------------------------------------read in SHIP CLASS String-----------------------------------------------------*/
//     // unsigned int length; can i just reuse this variable???
//     inFile.read(reinterpret_cast<char *>(&length), sizeof(length));
//
//     //dynamically allocate an array of chars exactly the right size
//     //make a temporary character pointer
//     tempArr = new char[length];
//     inFile.read(tempArr, length);
//
//     //store in our string var, then delete the temp char *
//     string shipClass = tempArr;
//     cout << "Class: " << shipClass << endl;
//     delete[] tempArr;
//
//     /*--------------------------------------read in ship Length SHORT-----------------------------------------------------*/
//     short shipLength;
//     inFile.read(reinterpret_cast<char *>(&shipLength), sizeof(shipLength));
//     cout << "Length: " << shipLength << endl;
//
//
//     /*------------------------------------read in Shield capacity INT---------------------------------------------------*/
//     int shieldCapacity;
//     inFile.read(reinterpret_cast<char *>(&shieldCapacity), sizeof(shieldCapacity));
//     cout << "Shield capacity: " << shieldCapacity << endl;
//
//
//     /*------------------------------------read in Shield capacity INT---------------------------------------------------*/
//     float maxWarp;
//     inFile.read(reinterpret_cast<char *>(&maxWarp), sizeof(maxWarp));
//     cout << "Maximum Warp: " << maxWarp << endl;
//
//
//     /*------------------------------------read in weapons count INT---------------------------------------------------*/
//     int weaponsCount;
//     inFile.read(reinterpret_cast<char *>(&weaponsCount), sizeof(weaponsCount));
//     cout << "Armaments:" << endl;
//
//     if (weaponsCount != 0) {
//         for (unsigned int i = 0; i < weaponsCount; i++) {
//             /*------------------------------------read in weapons name STRING---------------------------------------------------*/
//             inFile.read(reinterpret_cast<char *>(&length), sizeof(length));
//             //dynamically allocate an array of chars exactly the right size
//             //make a temporary character pointer
//             tempArr = new char[length];
//             inFile.read(tempArr, length);
//
//             //store in our string var, then delete the temp char *
//             string weaponName = tempArr;
//             delete[] tempArr;
//             cout << weaponName << ", ";
//
//             /*------------------------------------read in weapons power rating INT---------------------------------------------------*/
//             int powerRating;
//             inFile.read(reinterpret_cast<char *>(&powerRating), sizeof(powerRating));
//             cout << powerRating << ", ";
//
//             /*------------------------------------read in weapons power rating INT---------------------------------------------------*/
//             float powerConsumption;
//             inFile.read(reinterpret_cast<char *>(&powerConsumption), sizeof(powerConsumption));
//             cout << powerConsumption << endl;
//         }
//     } else {
//         cout << "Unarmed" << endl;
//     }
//     cout << endl;
// }
