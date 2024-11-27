#include <iostream>
#include <map>
#include <random>
#include <ctime>
#include <fstream>
#include <sstream>
using namespace std;

mt19937 random_mt;

int Random(int min, int max) {
    uniform_int_distribution<int> dist(min, max);
    return dist(random_mt);
}

void RollDice(int numberOfRolls, int numberOfSides) {
    map<int, int> results; /*key = num rolled, value = num times rolled*/

    //initialize map objs values to 0
    for (int i = 1; i <= numberOfSides; i++)
        results[i] = 0;

    //get results & store
    for (int i = 0; i < numberOfRolls; i++) {
        int result = Random(1, numberOfSides);
        results[result] += 1;
    }

    // create iterator, loop through mapp to print
    map<int, int>::iterator iter;
    for (iter = results.begin(); iter != results.end(); iter++) {
        cout << iter->first << ": " << iter->second << endl;
    }
}

struct StateInfo {
    int _perCapitaIncome;
    int _population;
    int _medianIncome;
    int _households;


    StateInfo(int perCapitaIncome, int population, int medianIncome, int households) {
        _perCapitaIncome = perCapitaIncome;
        _population = population;
        _medianIncome = medianIncome;
        _households = households;
    };
    void PrintInfo() {
        cout << "Population: " << _population << endl;
        cout << "Per Capita Income: " << _perCapitaIncome << endl;
        cout << "Median Household Income: " << _medianIncome << endl;
        cout << "Number of Households: " << _households << endl;
    }
};


int main() {
    cout << "1. Random Numbers\n";
    cout << "2. State Info\n";

    int option;
    cin >> option;

    if (option == 1) {
        int randomSeed;
        cout << "Random seed value: ";
        cin >> randomSeed;
        random_mt.seed(randomSeed);

        int rollNum;
        cout << "Number of times to roll the die: ";
        cin >> rollNum;

        int sideNum;
        cout << "Number of sides on this die: ";
        cin >> sideNum;

        // Roll Dice
        RollDice(rollNum, sideNum);
    } else if (option == 2) {
        // Load the states
        map<string, StateInfo> myMap;


        ifstream inFile("states.csv");
        string lineFromFile;
        string name;
        int perCapInc;
        int pop;
        int medInc;
        int numHouse;

        //get the first line, just discard it
        getline(inFile, lineFromFile);

        while (getline(inFile, lineFromFile)) {
            istringstream stream(lineFromFile);

            getline(stream, name, ',');

            string token;
            getline(stream, token, ',');
            perCapInc = stoi(token);

            getline(stream, token, ',');
            pop = stoi(token);
            getline(stream, token, ',');
            medInc = stoi(token);
            getline(stream, token, ',');
            numHouse = stoi(token);

            StateInfo state(perCapInc, pop, medInc, numHouse);

            myMap.emplace(name, state);
        }

        cout << "1. Print all states\n";
        cout << "2. Search for a state\n";
        int opt;
        cin >> opt;

        if (opt == 1) {
            map<string, StateInfo>::iterator iter;
            for (iter = myMap.begin(); iter != myMap.end(); iter++) {
                cout << iter->first << endl;
                iter->second.PrintInfo();
            }
        } else if (opt == 2) {
            string state;
            cin >> state;

            auto found = myMap.find(state);
            if (found == myMap.end())
                cout << "No match found for " << state;
            else {
                cout << found->first << endl;
                found->second.PrintInfo();
            }
        }

        // Get input for option 1 (show all states) or 2 (do a search for a particular state)
    }

    return 0;
}
