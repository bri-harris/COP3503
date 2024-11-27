#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, vector<string>> dictionary;

    ifstream inFile("dict.txt");
    string lineFromFile;

    /*-----------------------------------------------------------load dict data from file---------------*/

    while (getline(inFile, lineFromFile)) {
        // Break the line into 2 parts: Word | Definition
        int delimiter = lineFromFile.find_first_of('|');
        string word = lineFromFile.substr(0, delimiter);
        string definition = lineFromFile.substr(delimiter + 1);

        /*dict[] creates something it doesnt exist or retrieves it if it already exists
         * thus covering each possibility. Since t-his is a vector, it just adds the entry
         thus storing the pair*/
        dictionary[word].push_back(definition);
    }
    cout << "Num of Entries: " << dictionary.size() << endl;

    string input;
    cout << "Enter a word: ";
    getline(cin, input);



    for (unsigned int i = 0; i < dictionary[input].size(); i++)
        cout << dictionary[input][i] << endl;


    /*STORE ONLY ONE KEY AT A TIME*/
    // unordered_map<string, string> dictionary;
    //
    // ifstream inFile("dict.txt");
    // string lineFromFile;
    //
    // /*-----------------------------------------------------------load dict data from file---------------*/
    //
    // while (getline(inFile, lineFromFile)) {
    //     // Break the line into 2 parts: Word | Definition
    //     int delimiter = lineFromFile.find_first_of('|');
    //     string word = lineFromFile.substr(0, delimiter);
    //     string definition = lineFromFile.substr(delimiter + 1);
    //
    //     //store the pair, emplace returns pair<unordered_map<string, string>::iterator, bool>
    //     auto result = dictionary.emplace(word, definition);
    //     if (result.second == false) // key already exists
    //         cout << word << " already has an entry" << endl;
    // }
    // cout << "Num of Entries: " << dictionary.size() << endl;
    //
    // string input;
    // cout << "Enter a word: ";
    // getline(cin, input);
    // cout << dictionary[input] << endl;


    return 0;
}
