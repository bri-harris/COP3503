#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Hero.h"
using namespace std;


void ReadFromHerosFile(string filePath, vector<Hero>& output) {
    ifstream inFile(filePath);

    if (inFile.is_open()) {
        string dataFromFile;

        // //1. Read the count
        getline(inFile, dataFromFile);
        int count = stoi(dataFromFile);

        //2. for (count) read each individual obj
        for (int i = 0; i < count; i++) {
            string name;
            getline(inFile, name);

            getline(inFile, dataFromFile);
            int strength = stoi(dataFromFile);

            getline(inFile, dataFromFile);
            int hitpoints = stoi(dataFromFile);

            Hero heroObjFromFile(name, strength, hitpoints);
            output.push_back(heroObjFromFile);
        }
    } else {
        cout << "Error: " << filePath << " could not be opened." << endl;
    }
}

void ReadFromCSVFile(string filePath, vector<Hero>& output) {
    ifstream csv(filePath);

    //1. Read header from file, -> ignore it
    string lineFromFile;
    getline(csv, lineFromFile);

    //2.Get the raw data from the file, 1 line at a time
    while (getline(csv, lineFromFile)) {
        //3.Convert that line(string) into stream of data
        istringstream stream(lineFromFile);

        Hero someObj;
        someObj.Deserialize(stream);
        output.push_back(someObj);
    }
}

int main() {
    vector<Hero> heroes;

    //Read a data file w a count
    ReadFromHerosFile("data/info.heroes", heroes);

    //Read a CSV File
    ReadFromCSVFile("data/heroes.csv", heroes);

    for (unsigned int i = 0; i < heroes.size(); i++) {
        heroes[i].PrintInfo();
        if (i < heroes.size() - 1) { cout << endl; }
    }

    return 0;
}
