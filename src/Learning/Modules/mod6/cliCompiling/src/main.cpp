#include <iostream>
using namespace std;
#include "Hero.h"

int main() {
    string name;
    int strength;
    int hitpoints;

    cout << "Enter a name: ";
    getline(cin, name);

    cout << "Enter strength value: ";
    cin >> strength;

    cout << "Enter hitpoints value: ";
    cin >> hitpoints;

    Hero hero(name, strength, hitpoints);
    cout << "Hero data: " << endl;
    hero.PrintInfo();

    return 0;
}
