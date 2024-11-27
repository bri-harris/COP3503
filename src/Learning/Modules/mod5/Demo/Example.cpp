#include <iostream>
#include <string>
#include <vector>
#include "DynamicArray.h"
using namespace std;


void ExampleOne() {
    vector<int> numbers;
    // initialize 1-10
    for (int i = 1; i <= 10; i++)
        numbers.push_back(i);


    //print list backwards
    for (unsigned int i = numbers.size() - 1;
         i >= 0;
         i--)
        cout << numbers[i] << endl;
}

void ExampleTwo() {
}

int main() {
    ExampleOne();
    //ExampleTwo();
    return 0;
}


// int main() {
//     /*
//     DynamicArray<string> heroes(100);
//     heroes.Add("Batman");
//     heroes.Add("Robin");
//     heroes.Add("Batgirl");
//     heroes.Add("Alfred");
//
//     heroes.Print();
//
//     DynamicArray<string> marvelHeros;
//     marvelHeros.Add("Spider-Man");
//     marvelHeros.Add("Ms. Marvel");
//     marvelHeros.Add("Thor");
//
//     DynamicArray<string> heroes2 = heroes;
//     heroes2.Add("Wolverine");
//     if (heroes != heroes2) cout << "The 2 lists are not equal" << endl;
//     else cout << "The 2 lists are equal" << endl;
//
//     DynamicArray<string> villians;
//     villians.Add("Joker");
//     villians.Add("Killer Croc");
//     villians.Add("Two-Face");
//     villians.Add("Bane");
//
//     // combine 2 lists of heros
//     DynamicArray<string> combined = heroes + marvelHeros + villians;
//     */
//
//
//     return 0;
// }
