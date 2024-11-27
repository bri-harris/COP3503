#include <iostream>
#include "DynamicArray.h"
using namespace std;


int main() {
    DynamicArray array;

    array.Add(500);
    array.Add(200);
    array.Add(199);
    array.Add(299);
    array.Add(399);

    DynamicArray copy = array; // copy constructor
    copy.Add(100);
    copy.Add(200);
    copy.Add(300);

    copy.Print();

    //reset to original aray
    copy = array; //copy assignment operator

    array.Print();
    copy.Print();

    return 0;
}
