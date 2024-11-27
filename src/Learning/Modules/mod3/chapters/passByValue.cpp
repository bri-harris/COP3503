// #include <iostream>
// using namespace std;
//
// void ConvHrMin(int timeVal, int hrVal, int minVal) {
//     hrVal = timeVal / 60;
//     minVal = timeVal % 60;
// }
//
// int main() {
//     int totTime, usrHr, usrMin = 0;
//
//     cout << "Enter total minutes: ";
//     cin >> totTime;
//     ConvHrMin(totTime, usrHr, usrMin);
//
//     cout << usrHr << " hrs ";
//     cout << usrMin << " mins" << endl;
//
//     return 0;
// }
// #include <iostream>
// using namespace std;
//
// int main() {
//     int usrValInt;
//     int &usrValRef = usrValInt; // Refers to usrValInt
//
//     cout << "Enter an integer: ";
//     cin >> usrValInt;
//
//     cout << "We wrote your integer to usrValInt." << endl;
//     cout << "usrValInt is: " << usrValInt << "." << endl;
//     cout << "usrValRef refers to usrValInt, and is: " << usrValRef << "." << endl;
//
//     usrValInt = 99;
//     cout << endl << "We assigned usrValInt with 99." << endl;
//     cout << "usrValInt is now: " << usrValInt << "." << endl;
//     cout << "usrValRef is now: " << usrValRef << "." << endl;
//     cout << "Note that usrValRef refers to usrValInt, so it changed too." << endl;
//     return 0;
// }


// #include <iostream>
// using namespace std;
//
// void GetVolume(int &userGallons, int &userPints) {
//     cin >> userGallons;
//     cin >> userPints;
// }
//
// int main() {
//     int usrGallons;
//     int usrPints;
//
//     GetVolume(usrGallons, usrPints);
//
//     cout << usrGallons << " gallons and " << usrPints << " pints" << endl;
//
//     return 0;
// }
// #include <iostream>
// using namespace std;
//
// bool GetWeight(int &totalMilligrams, int grams, int milligrams) {
//     if (grams >= 0 & milligrams >= 0) {
//         totalMilligrams = grams * 1000 + milligrams;
//         return true;
//     }
//     return false;
// }
//
// int main() {
//     int totalMilligrams;
//     int grams;
//     int milligrams;
//     bool valid;
//
//     totalMilligrams = 0;
//     cin >> grams;
//     cin >> milligrams;
//
//     valid = GetWeight(totalMilligrams, grams, milligrams);
//
//     if (valid) {
//         cout << "Total milligrams: " << totalMilligrams << endl;
//     } else {
//         cout << "Invalid. Total milligrams: " << totalMilligrams << endl;
//     }
//
//     return 0;
// }
