#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void WriteNums(string filePath, vector<int>& nums, char delimiter) {
    ofstream file(filePath);
    if (file.is_open()) {
        for (unsigned int i = 0; i < nums.size(); i++) {
            file << nums[i];

            if (i < nums.size() - 1)
                file << delimiter;
        }
    } else cout << "Error, File " << filePath << " was not opened.";
}

void WriteNums(ofstream& file, vector<int>& nums, char delimiter) {
    for (unsigned int i = 0; i < nums.size(); i++) {
        file << nums[i];

        if (i < nums.size() - 1)
            file << delimiter;
    }
}

int main() {
    vector<int> nums;
    for (int i = 0; i < 20; i++)
        nums.push_back(rand() % 50 + 1);

    WriteNums("data/file1.txt", nums, ',');
    WriteNums("data/file2.txt", nums, '\n');
    return 0;
}
