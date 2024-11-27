#include <fstream>
#include <ios>
using namespace std;

int main() {
    fstream file("BinaryFile.bin", ios_base::in | ios_base::binary);
    file.read(char*s, std::streamsize n);

    // int value;
    //
    // fstream file("BinaryFile.bin", ios_base::in | ios_base::binary);
    // file.read(reinterpret_cast<char *>(&value), 4);
    // float pi = 3.14;
    // double biggerPi = 3.14158;
    // int notAPi = 3;
    // string pie = "Apple";
    //
    // fstream file("BinaryFile.bin", ios_base::out | ios_base::binary);
    // if (file.is_open()) {
    //     file.write(reinterpret_cast<char *>(&pi), sizeof(pi));
    //     file.write(reinterpret_cast<char *>(&biggerPi), sizeof(biggerPi));
    //     file.write(reinterpret_cast<char *>(&notAPi), sizeof(notAPi));
    //
    //
    //     //writing a string, 2 steps
    //     //1. write length of string, include Nul-terminator '\0'
    //     unsigned int length = pie.size() + 1;
    //     file.write(reinterpret_cast<char *>(&length), sizeof(length));
    //
    //     //2. write the string data itself
    //     //c_str(), returns the "real" str data as a char*
    //     file.write(pie.c_str(), length);
    // }

    // ofstream file("testing.bin");
    //
    // int x = 10;
    // file.write(reinterpret_cast<char *>(&x), 4);
    // //&x == int*
    //
    // short y = 22;
    // file.write(reinterpret_cast<char *>(&y), 2);
    // //*y == short*
    //
    // double z = 3.3;
    // file.write(reinterpret_cast<char *>(&z), 8);
    // //*z == double*
    //
    // int arrOfInts[3] = {2, 4, 6}; //arrOfInts == int*
    // file.write(reinterpret_cast<char *>(arrOfInts), 12);
    //
    // char a = '$';
    // file.write(&a, 1);

    return 0;
}
