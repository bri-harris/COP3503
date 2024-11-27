#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


int main() {
    vector<int> numbers;

    //generate random numbers
    for (int i = 0; i < 20; i++)
        numbers.push_back(rand() % 50 + 1);

    //write values to a text file
    ofstream textFile("data/numbers.txt");
    textFile << numbers.size() << endl;
    for (unsigned int i = 0; i < numbers.size(); i++)
        textFile << numbers[i] << endl;

    //write values to a binary file
    // "bin" is just an extension, it doesnt make it binary
    //ios_base::binary flag => open file in binary mode
    ofstream binaryFile("data/numbers.bin", ios_base::binary);

    unsigned int size = numbers.size();

    binaryFile.write(reinterpret_cast<char *>(&size), sizeof(size));

    for (int i = 0; i < 20; i++)
        binaryFile.write(reinterpret_cast<char *>(&numbers[i]), sizeof(numbers[i]));

    return 0;
}
