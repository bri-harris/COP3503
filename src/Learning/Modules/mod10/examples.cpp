#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    // Store some quiz scores
    map<string, int> scores;

    // Add 2 pair <string, int> using emplace
    scores.emplace("Lee", 85);
    scores.emplace("Joseph", 78);

    // Add 2 pair <string, int> using operator[]
    scores["Alberto"] = 79;
    scores["Martina"] = 92;

    while (true) {
        string input;
        cout << "Enter a name to search for (-1 to quit): ";
        getline(cin, input);

        if (input == "-1") break;
        // if (input == "size") cout << "num of elements: " << scores.size() << endl;
        else {
            // 1. Convert User input to lower case
            string inputLower = input;
            for (unsigned int i = 0; i < inputLower.size(); i++)
                inputLower[i] = tolower(inputLower[i]);


            // 2. Iterate over all elements in the container
            bool found = false;
            for (map<string, int>::iterator iter = scores.begin(); iter != scores.end(); ++iter) {
                // 3. convert the key of an element to lowercase
                string keyLower = iter->first;
                for (unsigned int i = 0; i < keyLower.size(); i++)
                    keyLower[i] = tolower(keyLower[i]);

                // 4.  compare the lower input to the lower key for match
                if (keyLower == inputLower) {
                    // 5. use that particular element
                    cout << "The score for " << iter->first << " is " << iter->second << endl;
                    found = true;
                    break;
                }
            }

            if (!found) cout << input << " was not found." << endl;


            // // Search for the key to verify it exists before trying to use it
            // if (scores.find(input) != scores.end())
            //     cout << "The score for " << input << " is " << scores.at(input) << endl;
            // else
            //     cout << input << " was not found." << endl;
        }
    }


    return 0;
}
