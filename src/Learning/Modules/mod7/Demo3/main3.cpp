#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


int main() {
    vector<int> nums;
    ifstream inFile("data/file2.txt");

    if (inFile.is_open()) {
        string data;
        // while (getline(inFile, data, '\n')) {
        //     nums.push_back(stoi(data));
        // }

        // int aVal;
        // inFile.eof();
        // while (inFile >> aVal) nums.push_back(aVal);

        int aVal;

        while (!inFile.eof()) {
            //Read one value
            inFile >> aVal;
            //Do something with
            nums.push_back(aVal);
        }

        cout << "Numbers in file: " << nums.size() << endl;
        for (unsigned int i = 0; i < nums.size(); i++) {
            cout << nums[i] << ' ';
        }

        return 0;
    }
}
