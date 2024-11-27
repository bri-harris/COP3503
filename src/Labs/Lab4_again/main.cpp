#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include "extrafile.h"
using namespace std;


void ReadFromCSVFile(string filePath, vector<extrafile::Lego>& output) {
	ifstream csv(filePath);

	// 1. read header from file
	string fileLine;
	getline(csv, fileLine);

	// 2. Get the raw data from file 1 line at a time
	while (getline(csv, fileLine)) {
		// 3 . Convert line, which is a string, into data stream
		istringstream stream(fileLine);

		string token;

		getline(stream, token, ',');
		int number = stoi(token);

		string theme;
		getline(stream, theme, ',');

		string name;
		getline(stream, name, ',');

		getline(stream, token, ',');
		int minifigs = stoi(token);

		getline(stream, token, ',');
		int pieces = stoi(token);

		getline(stream, token, ',');
		double usPrice = stod(token);

		extrafile::Lego lego(number, theme, name, minifigs, pieces, usPrice);
		output.push_back(lego);
	}
}

// int main() {
// 	cout << std::fixed << setprecision(2);
// 	cout << "Which file(s) to open?\n";
// 	cout << "1. lego1.csv" << endl;
// 	cout << "2. lego2.csv" << endl;
// 	cout << "3. lego3.csv" << endl;
// 	cout << "4. All 3 files" << endl;
// 	int option;
// 	cin >> option;
//
// 	/*======= Load data from file(s) =======*/
//
//
// 	cout << "1. Most Expensive set" << endl;
// 	cout << "2. Largest piece count" << endl;
// 	cout << "3. Search for set name containing..." << endl;
// 	cout << "4. Search themes..." << endl;
// 	cout << "5. Part count information" << endl;
// 	cout << "6. Price information" << endl;
// 	cout << "7. Minifigure information" << endl;
// 	cout << "8. If you bought one of everything..." << endl;
// 	cout << "0. Exit" << endl;
//
// 	int choice;
// 	cin >> choice;
// 	cin.get(); // Clear newline character for any later input
//
// 	/*======= Print out how many sets were loaded =======*/
// 	/*======= Based on the choice, execute the appropriate task and show the results =======*/
// 	return 0;
// }

int main() {
	cout << std::fixed << setprecision(2);
	cout << "Which file(s) to open?\n";
	cout << "1. lego1.csv" << endl;
	cout << "2. lego2.csv" << endl;
	cout << "3. lego3.csv" << endl;
	cout << "4. All 3 files" << endl;
	int option;
	cin >> option;

	// /*======= Load data from file(s) =======*/

	cout << "1. Most Expensive set" << endl;
	cout << "2. Largest piece count" << endl;
	cout << "3. Search for set name containing..." << endl;
	cout << "4. Search themes..." << endl;
	cout << "5. Part count information" << endl;
	cout << "6. Price information" << endl;
	cout << "7. Minifigure information" << endl;
	cout << "8. If you bought one of everything..." << endl;
	cout << "0. Exit" << endl;

	int choice;
	cin >> choice;
	cin.get(); // Clear newline character for any later input


	vector<extrafile::Lego> vData;

	if (option == 1) {
		ReadFromCSVFile("data/lego1.csv", vData);
	} else if (option == 2) {
		ReadFromCSVFile("data/lego2.csv", vData);
	} else if (option == 3) {
		ReadFromCSVFile("data/lego3.csv", vData);
	} else if (option == 4) {
		ReadFromCSVFile("data/lego1.csv", vData);
		ReadFromCSVFile("data/lego2.csv", vData);
		ReadFromCSVFile("data/lego3.csv", vData);
	}

	extrafile dArr(vData);

	/*======= Print out how many sets were loaded =======*/
	cout << "Total number of sets: " << dArr.GetTotalSets() << endl << endl;


	/*======= Based on the choice, execute the appropriate task and show the results =======*/
	if (choice == 1) {
		dArr.PrintMostExpensiveSet();
	} else if (choice == 2) {
		dArr.PrintLargestPieceSet();
	} else if (choice == 3) {
		bool trueOrFalse = dArr.Search(dArr._termSearch);
		if (trueOrFalse) {
			dArr.PrintMatchingNames(dArr._termSearch);
		}
	} else if (choice == 4) {
		bool trueOrFalse = dArr.Search(dArr._themeSearch);
		if (trueOrFalse) {
			dArr.PrintMatchingThemes(dArr._themeSearch);
		}
	} else if (choice == 5) {
		dArr.PrintPartCountInfo();
	} else if (choice == 6) {
		dArr.PrintAvgPriceInfo();
	} else if (choice == 7) {
		dArr.PrintMiniFigInfo();
	} else if (choice == 8) {
		dArr.PrintOneOfEverything();
	} else if (choice == 0) {
	}

	return 0;
}

