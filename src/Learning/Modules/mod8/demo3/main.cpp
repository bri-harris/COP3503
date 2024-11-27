#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void WriteNumbersToBinaryFile() {
    vector<int> numbers;

    //Generate some random Numbers
    for (int i = 0; i < 20; i++)
        numbers.push_back(rand() / 50 + 1);

    //write values to a binary file, open in binary mode
    ofstream binaryFile("data/numbers.bin", ios_base::binary);

    /*-----------------------------------file format-----------------------------------*/
    //4 bytes - Count of all the numbers in the file
    //count * 4 bytes - the numbers themselves (each a 4-byte integer

    //write out the count
    unsigned int size = numbers.size();
    binaryFile.write(reinterpret_cast<char *>(&size), sizeof(size));

    //write out data
    for (unsigned int i = 0; i < numbers.size(); i++) {
        binaryFile.write(reinterpret_cast<char *>(&numbers[i]), sizeof(numbers));
    }
}


int main() {
    ifstream inFile("data/numbers.bin", ios_base::binary);
    /*-----------------------------------file format-----------------------------------*/
    //4 bytes - Count of all the numbers in the file
    int count;
    inFile.read(reinterpret_cast<char *>(&count), sizeof(count));
    cout << "Count: " << count << endl;

    vector<int> numbers(count);

    for (int i = 0; i < count; i++) {
        inFile.read(reinterpret_cast<char *>(&numbers[i]), sizeof(numbers[i]));

        cout << "Number[" << i << "]: " << numbers[i] << "\t";
    }


    //count * 4 bytes - the numbers themselves (each a 4-byte integer


    // vector<int> numbers;
    // ifstream file1("data/file1.txt");
    // string a;
    // while (getline(file1, a, ','))
    //     numbers.push_back(stoi(a));
    //
    //
    // ofstream binaryFile("data/numbers.bin", ios_base::binary);
    //
    // int numsSize = numbers.size();
    // binaryFile.write(reinterpret_cast<char *>(&numsSize), 4);
    //
    // for (unsigned i = 0; i < numbers.size(); i++)
    //     binaryFile.write(reinterpret_cast<char *>(&numbers[i]), sizeof(numbers[i]));
    //
    //
    // // vector<int> fileNums;
    // // ofstream file2("data/file2.txt");
    // // for (unsigned i = 0; i < fileNums.size(); i++)
    // //     file2 << fileNums[i] << endl;


    return 0;
}
