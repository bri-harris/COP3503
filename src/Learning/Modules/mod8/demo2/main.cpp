#include <iostream>
#include<fstream>
#include<vector>
#include"Hero.h"
using namespace std;

int main() {
    // ofstream outFile("data/heros.bin");
    // Hero h1("Thor Odinson", 100, 250);
    //
    //
    // //strings / variable data need 2 step process
    // //1. write the AMOUNT of data, strings need null terminating char
    // //2. write the data itself
    //
    // string name = h1.GetName();
    // unsigned int length = name.size() + 1;
    // outFile.write(reinterpret_cast<char *>(&length), sizeof(length));
    // outFile.write(name.c_str(), length);
    //
    //
    // int strength = h1.GetStrength();
    // outFile.write(reinterpret_cast<char *>(&strength), sizeof(strength));
    //
    //
    // int hitpoints = h1.GetHitpoints();
    // outFile.write(reinterpret_cast<char *>(&hitpoints), sizeof(hitpoints));

    //
    // vector<Hero> heroes;
    // Hero h1("Thor Odinson", 100, 250);
    // Hero h2("Batman", 50, 120);
    // Hero h3;
    // heroes.push_back(h1);
    // heroes.push_back(h2);
    // heroes.push_back(h3);
    //
    // ofstream outFile("data/heros.bin", ios_base::binary);
    //
    // //write the amount of data
    // unsigned int count = heroes.size();
    // outFile.write(reinterpret_cast<char *>(&count), sizeof(count));
    // //write the data itself
    // for (unsigned int i = 0; i < heroes.size(); i++) {
    //     string name = heroes[i].GetName();
    //     unsigned int length = name.size() + 1;
    //     outFile.write(reinterpret_cast<char *>(&length), sizeof(length));
    //     outFile.write(name.c_str(), length);
    //
    //     int strength = heroes[i].GetStrength();
    //     outFile.write(reinterpret_cast<char *>(&strength), sizeof(strength));
    //
    //     int hitpoints = heroes[i].GetHitpoints();
    //     outFile.write(reinterpret_cast<char *>(&hitpoints), sizeof(hitpoints));
    // }


    vector<Hero> heroes;
    Hero h1("Thor Odinson", 100, 250);
    Hero h2("Batman", 50, 120);
    Hero h3;
    heroes.push_back(h1);
    heroes.push_back(h2);
    heroes.push_back(h3);


    ofstream outFile("data/heroes.bin", ios_base::binary);
    unsigned int count = heroes.size();
    outFile.write(reinterpret_cast<char *>(&count), sizeof(count));

    for (unsigned int i = 0; i < heroes.size(); i++)
        heroes[i].Serialize(outFile);


    return 0;
}
