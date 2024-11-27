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

    cout << "Which file(s) to open?\n";
    cout << "1. friendlyships.shp" << endl;
    cout << "2. enemyships.shp" << endl;
    cout << "3. Both files" << endl;
    int option;
    cin >> option;

    /* Load files here */
    ReadDataFromFile(ships, option);

    cout << "1. Print all ships" << endl;
    cout << "2. Starship with the strongest weapon" << endl;
    cout << "3. Strongest starship overall" << endl;
    cout << "4. Weakest ship (ignoring unarmed)" << endl;
    cout << "5. Unarmed ships" << endl;

    cin >> option;

    if (option == 1) {
        PrintAllShips(ships);
    } else if (option == 2) {
        extrafile weapon = GetMostPowerfulWeapon(ships);
        weapon.PrintShip();
    } else if (option == 3) {
        extrafile mostPowerful = GetMostPowerfulShip(ships);
        mostPowerful.PrintShip();
    } else if (option == 4) {
        extrafile weakest = GetWeakestShip(ships);
        weakest.PrintShip();
    } else if (option == 5) {
        vector<extrafile> unarmed = GetUnarmedShips(ships);
        PrintAllShips(unarmed);
    }


    return 0;
}
