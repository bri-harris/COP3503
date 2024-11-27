#include <iostream>
#include "DynArr.h"
using namespace std;

int main() {
    DynArr arr(10);
    arr.Add(500);
    arr.Add(400);
    arr.Add(300);
    arr.Add(200);
    arr.Add(100);
    arr.Add(99);
    arr.Add(88);
    arr.Add(77);
    arr.Print();

    DynArr copy = arr;
    DynArr copyAssign;

    copy.Print();

    copyAssign = copy;
    copyAssign.Print();

    return 0;
}
