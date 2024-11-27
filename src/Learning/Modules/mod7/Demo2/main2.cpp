#include <iostream>
#include <fstream>
#include <vector>
#include "Hero.h"
using namespace std;


int main() {
    ofstream outFile("data/info.csv");
    Hero h1("Thor Odinson", 50, 250);
    Hero h2("Batman", 50, 120);
    Hero h3;

    vector<Hero> heroes;
    heroes.push_back(h1);
    heroes.push_back(h2);
    heroes.push_back(h3);

    //wrtie header data to the file
    outFile << "Name," << "Strength," << "Hitpoints,";
    outFile << "Max Hitpoints," << "Level," << "Experience" << endl;

    //Write the Heros to a file
    for (unsigned int i = 0; i < heroes.size(); i++) {
        heroes[i].Serialize(outFile);

        if (i < heroes.size() - 1)
            outFile << endl;
    }

    return 0;
}
