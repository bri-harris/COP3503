// #include <iostream>
// using namespace std;
//
// // Program is stored in code memory
//
// int myGlobal = 33; // In static memory
//
// void MyFct() {
//     int myLocal; // On stack
//     myLocal = 999;
//     cout << " " << myLocal;
// }
//
// int main() {
//     int myInt; // On stack
//     int *myPtr = nullptr; // On stack
//     myInt = 555;
//
//     myPtr = new int; // In heap
//     *myPtr = 222;
//     cout << *myPtr << " " << myInt;
//     delete myPtr; // Deallocated from heap
//
//     MyFct(); // Stack grows, then shrinks
//
//     return 0;
// }
// #include <iostream>
// using namespace std;
//
// class MyClass {
// public:
//     MyClass();
//
// private:
//     int *subObj;
// };
//
// MyClass::MyClass() {
//     subObj = new int; // Allocate sub-object
//     *subObj = 0;
// }
//
//
// int main() {
//     MyClass *tempObj;
//
//     tempObj = new MyClass;
//     delete tempObj;
//     return 0;
// }
