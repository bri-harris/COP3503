#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "Vehicle.h"
using namespace std;


int main() {
    ifstream aFile("Vehicles.csv"); //create instance of ifstream class

    string singleLine; // var to store a line of file as getline() outputs
    vector<Vehicle> vehicles; //store object for later use

    //while getline() finds a line in aFile, and outputs into singleLine
    while (getline(aFile, singleLine)) {
        istringstream stream(singleLine); //create a stream of data w/ singleLine

        string make;
        string model;
        int miles;
        double price;

        //read into make & model directly
        getline(stream, make, ','); //read data stream till ','
        getline(stream, model, ',');


        //store results in var for data needing to be converted
        string token;
        getline(stream, token, ',');
        miles = stoi(token); //convert string into int & store in miles

        getline(stream, token, ',');
        price = stod(token); // convert string to double}

        Vehicle car(make, model, miles, price);
        vehicles.push_back(car);
    }
    // ifstream someFile("Vehicles.csv");
    // string singleLine;
    // getline(someFile, singleLine);
    //
    // istringstream stream(singleLine);
    // string token;
    //
    // while (getline(stream, token, ',')) {
    //     cout << token << "\t";

    // ifstream inFile("file2.txt");
    // int numFromFile;
    // vector<int> nums;
    //
    // if (inFile.is_open()) {
    //     while (inFile >> numFromFile) {
    //         nums.push_back(numFromFile);
    //     }
    // }

    // ifstream someFile("VehicleData");
    // string make;
    // string model;
    // double price;
    // int miles;
    //
    // if (someFile.is_open()) {
    //     getline(someFile, make);
    //     getline(someFile, model);
    //     someFile >> miles;
    //     someFile >> price;
    // }
    //
    // Vehicle car(make, model, miles, price);
    // someVector.push_bakc(car);
    //
    // cout << "Make: " << make << "\tModel: " << model;


    // ofstream someFile("SomeFile.txt");
    //
    // if (someFile.is_open()) {
    //     const float mmmPi = 3.1415f;
    //     someFile << "Hello World! (file edition) ";
    //     someFile << "Value of pi: " << mmmPi;
    //
    //     someFile.close();
    // }
    // someFile.open("file2.txt");
    // for (int i = 2; i <= 16; i *= 2) someFile << i << ' ';
    //
    // string make;
    // string model;
    // int miles;
    // double price;
    //
    // getline(cin, make);
    // getline(cin, model);
    // cin >> miles;
    // cin >> price;

    // ofstream otherFile;
    // otherFile.open("data/file1.xyz");
    //
    // if (someFile.is_open())
    //     cout << "opened!";

    // fstream aFile("file.ext", ios_base::out | ios_base::binary | ios_base::app);
    return
            0;
}
