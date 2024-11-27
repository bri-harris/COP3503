#include <vector>
#include <map>
#include <functional>
#include "Random.h"
using namespace std;


// void Foo(int a, float b) {
//     /*do something*/
// }
//
// class FuncHolder {
//     void (*_singleAction)(); //store a single function
//     vector<void(*)()> _actions; //store multiple functions
//
// public:
//     void AddAction(void (*a)()); //Add a pointer to the vector
//     void DoAllActions(); //storeCall all stored functions
// };
//
// int main() {
//     // //initialize an instance of the class
//     // //1st assign it a value, here we assign it a ƒ ptr
//     // function<void(int, float)> func = Foo;
//     //
//     // //call the obj like a function
//     // func(5, 2.9f);
//
//     return 0;
// }


// function<void()> otherFunction;
// function<bool(int)> someFunction;

// struct Over_X {
//     //Constructor customizes Functor
//     Over_X(int xVal) { _x = xVal; }
//
//     bool operator()(int num) {
//         return num > _x;
//     }
//
// private:
//     int _x;
// };
//
// int main() {
//     return 0;
// }

// // Functor
// struct OverTor20 {
//     bool operator()(int num) {
//         return num > 20;
//     }
// };
//
// //function ptr
// bool OverPtr20(int num) {
//     return num > 20;
// }
//
// int main() {
//     //make a list of random numbers 1-40
//     vector<int> nums;
//     for (int i = 0; i < 10; i++) {
//         nums.push_back(Random::Int(1, 40));
//     }
//
//     //Goal: count how many nums are > 20
//     int c1 = count_if(nums.begin(), nums.end(), OverTor20());
//     int c2 = count_if(nums.begin(), nums.end(), OverPtr20);
//
//     return 0;
// }


// class DieRoller {
//     map<int, int> _results;
//     int _max;
//
// public:
//     DieRoller(int sides) { _max = sides; }
//
//     int operator()() {
//         //roll a nume, store results
//         int roll = Random::Int(1, _max);
//         _results[roll]++;
//         return roll;
//     }
//     void Results() {
//         //print data
//     }
// };

//Functor
// struct Ascending {
//     bool operator()(int a, int b) {
//         return a > b;
//     }
// };

//sort w custom comparison, pass a functor
// void sortStuff(vector<int>& nums, Ascending compare) {
//     if (compare(nums[i], nums[i + 1])) {
//         //swap}
//     }
// }

//pass temp instance of the class
// SortStuff(someVector, Ascending());

// int main() {
//     // DieRoller tenSides(10);
//
// int val1 = tenSides();
// int val2 = tenSides();
// int val3 = tenSides();
//
// vector<int> nums;
// for (int i = 0; i < 5; i++) {
//     nums.push_back(tenSides());
// }

//     return 0;
// }


// int Random100() {
// }
//
// int (*ptr)() = Random100;
//
// int random = ptr();
//
//
// void DoSomething(int value);
//
// void (*p)(int) = DoSomething;
//
//
// bool Ascending(int a, int b) {
//     return a > b;
// }
// bool (*ptr)(int, int) = Ascending;
//
// using Comparison = bool(*)(int, int);
// Comparison myPtr = Ascending;
//
// //OG function Prototype
// void SortSome(std::vector<int>& nums, bool (*ptr)(int, int));
//pass pointer to the ƒ
// SortSome(someVector, Ascending);
// //fcn using alias for fcn ptr
// void SortSome(std::vector<int>& nums, Comparison c) {
//     if (c(nums[i], nums[i + 1])) {
//         // somthin;
//     }
// }
//
// template<typename T>
// void SortSome(std::vector<int>& nums, T compareFunc) {
//     if (compareFunc(nums[i], nums[i + 1])) {
//         //somethin;
//     }
// }
//
// SomeClass myObject;
// myObject();
//
// myObject.operator()();



