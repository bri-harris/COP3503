// #include <iostream>
// #include <vector>
// #include <string>
// #include <iomanip>

// using namespace std;

// string InputTitlesOutputTitles(string userPrompt) {
//     string input;
//     cout << userPrompt << endl;
//     getline(cin, input);
//     cout << "You entered: " << input << endl;
//     return input;
// }

// int main() {
//     string dataTitle = InputTitlesOutputTitles("Enter a title for the data:");
//     string col1 = InputTitlesOutputTitles("Enter the column 1 header:");
//     string col2 = InputTitlesOutputTitles("Enter the column 2 header:");


//     string input;
//     string strIn;
//     vector<string> strVector;
//     vector<int> intVector;

//     while (true) {
//         cout << "Enter a data point (-1 to stop input):" << endl;
//         getline(cin, input);
//         int i = input.find(',');
//         try {
//             if (i == -1) {
//                 try {
//                     int location = stoi(input);
//                     if (location == -1) {
//                         cout << endl;
//                         break;
//                     } else {
//                         throw runtime_error("Error: No comma in string.");
//                     }
//                 } catch (runtime_error e) {
//                     cout << e.what() << endl;
//                 }
//             }
//             if (int j = input.find_last_of(',') != i) {
//                 throw runtime_error("Error: Too many commas in input.");
//             }

//             strVector.push_back(input.substr(0, i));

//             string k = input.substr(i + 1);
//             intVector.push_back(stoi(k));

//             cout << "Data string: " << input.substr(0, i) << endl;
//             cout << "Data integer: " << stoi(k) << endl;
//         } catch (runtime_error &e) {
//             cout << e.what() << endl;
//         } catch (invalid_argument &e) {
//             cout << "Error: Comma not followed by an integer." << endl;
//         }
//     }

//     cout << setw(33) << right << dataTitle << endl;
//     cout << setw(20) << left << col1 << "|";
//     cout << setw(23) << right << col2 << endl;
//     cout << setfill('-') << setw(44) << "" << endl;
//     cout << setfill(' ');

//     const int vectorSize = strVector.size();
//     int z = 0;
//     while (z != vectorSize) {
//         cout << setw(20) << left << strVector[z] << "|";
//         cout << setw(23) << right << intVector[z] << endl;
//         z++;
//     }
//     cout << endl;

//     int y = 0;
//     while (y != vectorSize) {
//         cout << setw(20) << strVector[y] << " ";
//         cout << setfill('*') << setw(intVector[y]) << "" << endl;
//         cout << setfill(' ');
//         y++;
//     }


//     return 0;
// }

// //
// //
// // void PrintNumbers(vector<int> nums) {
// //     for (int num: nums) {
// //         cout << num << " ";
// //     }
// //     cout << endl;
// // }
// //
// // void PrintStrs(const vector<string> strings) {
// //     for (const auto &string: strings) {
// //         cout << string << " ";
// //     }
// //     cout << endl;
// // }
