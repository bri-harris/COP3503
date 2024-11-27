#include <iostream>
#include<fstream>
#include<vector>
#include"Hero.h"
using namespace std;

void WriteBinaryHeroData() {
    vector<Hero> heroes;
    Hero h1("Thor Odinson", 100, 250);
    Hero h2("Batman", 50, 120);
    Hero h3;
    heroes.push_back(h1);
    heroes.push_back(h2);
    heroes.push_back(h3);

    //1. Write the AMOUNT of data
    ofstream outFile("data/heros.bin", ios_base::binary);
    unsigned int count = heroes.size();

    //2. Write the data itself
    outFile.write(reinterpret_cast<char *>(&count), sizeof(count));

    for (unsigned int i = 0; i < heroes.size(); i++)
        heroes[i].Serialize(outFile);
}

void ReadDateFromFile(vector<Hero>& heroes) {
    /* FILE FORMAT
 * 4 byte count -- number of hero objects
 * for each hero obj...
 * String Name --- 4 byte count, length of name
 * Count bytes -- the actual string for the name
 *
 * 4 byte strength
 * 4 byte Hitpoints
 * 4 byte MAxHitpoints
 * 4 byte level
 * 4 byte experience
 */

    //Load data into the program
    ifstream inFile("data/heroes.bin", ios_base::binary);

    unsigned int count;
    inFile.read(reinterpret_cast<char *>(&count), sizeof(count));

    for (unsigned int i = 0; i < count; i++) {
        Hero someHero;
        someHero.Deserialize(inFile);
        heroes.push_back(someHero);
    }
}

int main() {
    vector<Hero> heroes;
    ReadDateFromFile(heroes);

    //Use that data for some purpose


    // //Load data into the program
    // ifstream inFile("data/heroes.bin", ios_base::binary);
    //
    // unsigned int count;
    // inFile.read(reinterpret_cast<char *>(&count), sizeof(count));
    //
    // for (unsigned int i = 0; i < count; i++) {
    //     Hero someHero;
    //     someHero.Deserialize(inFile);
    //     heroes.push_back(someHero);
    // }


    /* FILE FORMAT
 * 4 byte count -- number of hero objects
 * for each hero obj...
 * String Name --- 4 byte count, length of name
 * Count bytes -- the actual string for the name
 *
 * 4 byte strength
 * 4 byte Hitpoints
 * 4 byte MAxHitpoints
 * 4 byte level
 * 4 byte experience
 */

    //Use that data for some purpose


    // //Load data into the program
    // ifstream inFile("data/heroes.bin", ios_base::binary);
    //
    // unsigned int count;
    // inFile.read(reinterpret_cast<char *>(&count), sizeof(count));
    //
    // for (unsigned int i = 0; i < count; i++) {
    //     //read in one hero
    //
    //     /*--------------------------------------read in string--------------------------------------------------------*/
    //     unsigned int length;
    //     inFile.read(reinterpret_cast<char *>(&length), sizeof(length));
    //     //dynamically allocate an array of chars exactly the right size
    //     //make a temporary character pointer
    //     char* tempArray = new char[length];
    //     inFile.read(tempArray, length);
    //     //store in our string var
    //     string name = tempArray;
    //     delete[] tempArray;
    //
    //
    //     /*-------------------------------------read in integers----------------------------------------------------*/
    //     int str;
    //     int hp;
    //     int maxHp;
    //     int lvl;
    //     int exp;
    //     inFile.read(reinterpret_cast<char *>(&str), sizeof(str));
    //     inFile.read(reinterpret_cast<char *>(&hp), sizeof(hp));
    //     inFile.read(reinterpret_cast<char *>(&maxHp), sizeof(maxHp));
    //     inFile.read(reinterpret_cast<char *>(&lvl), sizeof(lvl));
    //     inFile.read(reinterpret_cast<char *>(&exp), sizeof(exp));
    //
    //
    //     /*-------------------------------------construct hero obj----------------------------------------------------*/
    //     Hero someHero(name, str, hp);
    //     someHero.PrintInfo();
    // }
    //


    return 0;
}
