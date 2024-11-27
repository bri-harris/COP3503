#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void WriteOutData() {
    ofstream outFile("data/data.bin", ios_base::binary);
    string name = "Batman";
    string nickname = "The Dark Knight";
    string sidekick = "Robin";

    int array[] = {2, 4, 6, 8, 10};
    float valueOne = 3.141592f;
    short valueTwo = 32;
    unsigned long long valueThree = 293871938571;

    //write a string
    unsigned int size = name.size() + 1;
    outFile.write(reinterpret_cast<char*>(&size), sizeof(size));
    outFile.write(name.c_str(), size);

    //write a string
    size = nickname.size() + 1;
    outFile.write(reinterpret_cast<char*>(&size), sizeof(size));
    outFile.write(nickname.c_str(), size);

    //write a string
    size = sidekick.size() + 1;
    outFile.write(reinterpret_cast<char*>(&size), sizeof(size));
    outFile.write(sidekick.c_str(), size);

    //Write an array
    for (int i = 0; i < 5; i++)
        outFile.write(reinterpret_cast<char*>(&array[i]), 4);

    //write the values
    outFile.write(reinterpret_cast<char*>(&valueOne), sizeof(float));
    outFile.write(reinterpret_cast<char*>(&valueTwo), sizeof(short));
    outFile.write(reinterpret_cast<char*>(&valueThree), sizeof(unsigned long long));
}
void ReadString(ifstream& file, string& outputStr) {
    unsigned int strLength;
    file.read(reinterpret_cast<char*>(&strLength), 4); //Read the length of the str
    char* buffer = new char[strLength]; // Allocate space temporarily to store the string data
    file.read(buffer, strLength); // Read into the temporary buffer
    outputStr = buffer; //Copy into a std::string object for long term storage
    delete[] buffer; //Delete temporary buffer
}
int ReadInt(ifstream& file) {
    int num;
    file.read(reinterpret_cast<char*>(&num), 4);
    return num;
}

template<typename T>
T ReadNumber(ifstream& file) {
    T num;
    file.read(reinterpret_cast<char*>(&num), sizeof(num));
    return num;
}

void ReadArrayOfInts(ifstream& file, int* numArr, int count) {
    for (int i = 0; i < count; i++)
        numArr[i] = ReadInt(file);
}

// class BinaryFileReader {
//     ifstream inFile;
//
// public:
//     BinaryFileReader(string fileToOpen) {
//         inFile.open(fileToOpen, ios_base::binary);
//     }
//     void ReadString(ifstream& file, string& outputStr) {
//         unsigned int strLength;
//         file.read(reinterpret_cast<char*>(&strLength), 4); //Read the length of the str
//         char* buffer = new char[strLength]; // Allocate space temporarily to store the string data
//         file.read(buffer, strLength); // Read into the temporary buffer
//         outputStr = buffer; //Copy into a std::string object for long term storage
//         delete[] buffer; //Delete temporary buffer
//     }
//     int ReadInt(ifstream& file) {
//         int num;
//         file.read(reinterpret_cast<char*>(&num), 4);
//         return num;
//     }
//
//     template<typename T>
//     T ReadNumber(ifstream& file) {
//         T num;
//         file.read(reinterpret_cast<char*>(&num), sizeof(num));
//         return num;
//     }
//
//     void ReadArrayOfInts(ifstream& file, int* numArr, int count) {
//         for (int i = 0; i < count; i++)
//             numArr[i] = ReadInt(file);
//     }
//
// };


int main() {
    ifstream inFile("data/data.bin", ios_base::binary);

    string name, nickname, sidekick;
    ReadString(inFile, name);;
    ReadString(inFile, nickname);
    ReadString(inFile, sidekick);;

    int numbers[5];
    ReadArrayOfInts(inFile, numbers, 5);


    float valueOne = ReadNumber<float>(inFile);
    short valueTwo = ReadNumber<short>(inFile);
    unsigned long long valueThree = ReadNumber<unsigned long long>(inFile);

    cout << "Data from the file:" << endl;
    cout << "Name: " << name << endl;
    cout << "Nickname: " << nickname << endl;
    cout << "Sidekick: " << sidekick << endl;

    for (int i = 0; i < 5; i++)
        cout << "Array[" << i << "]: " << numbers[i] << endl;

    cout << "Value one (float): " << valueOne << endl;
    cout << "Value two (short): " << valueTwo << endl;
    cout << "Value one (unsigned long long): " << valueThree << endl;
}

// int main() {
//     ifstream inFile("data/data.bin", ios_base::binary);
//     string name;
//     string nickname;
//     string sidekick;
//
//Read the name from the file
// unsigned int strLength;
// inFile.read(reinterpret_cast<char*>(&strLength), 4); //Read the length of the str
// char* buffer = new char[strLength]; // Allocate space temporarily to store the string data
// inFile.read(buffer, strLength); // Read into the temporary buffer
// name = buffer; //Copy into a std::string object for long term storage
// delete[] buffer; //Delete temporary buffer
//
// // Read the nickname from the file
// inFile.read(reinterpret_cast<char*>(&strLength), 4);
// buffer = new char[strLength];
// inFile.read(buffer, strLength);
// nickname = buffer;
// delete[] buffer;
//
// // Read the nickname from the file
// inFile.read(reinterpret_cast<char*>(&strLength), 4);
// buffer = new char[strLength];
// inFile.read(buffer, strLength);
// sidekick = buffer;
// delete[] buffer;

//     int numbers[5];
//     for (int i = 0; i < 5; i++)
//         inFile.read(reinterpret_cast<char*>(&numbers[i]), 4);
//
//     float valueOne;
//     short valueTwo;
//     unsigned long long valueThree;
//
//     inFile.read(reinterpret_cast<char*>(&valueOne), sizeof(valueOne));
//     inFile.read(reinterpret_cast<char*>(&valueTwo), sizeof(valueTwo));
//     inFile.read(reinterpret_cast<char*>(&valueThree), sizeof(valueThree));
//
//     cout << "Data from the file:" << endl;
//     cout << "Name: " << name << endl;
//     cout << "Nickname: " << nickname << endl;
//     cout << "Sidekick: " << sidekick << endl;
//
//     for (int i = 0; i < 5; i++)
//         cout << "Array[" << i << "]: " << numbers[i] << endl;
//
//     cout << "Value one (float): " << valueOne << endl;
//     cout << "Value two (short): " << valueTwo << endl;
//     cout << "Value one (unsigned long long): " << valueThree << endl;
// }
