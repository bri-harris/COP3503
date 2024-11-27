#include <string>
#include <iostream>
#include <vector>
#include "Hero.h"
using namespace std;

class Enemy {
    Hero* _target; //who is the enemy targeting?
public:
    void SetTarget(Hero* target);
    void PrintTargetInfo();
};

void Enemy::SetTarget(Hero* target) {
    _target = target;
    cout << "Target Aquired! Tracking " << target->GetName() << endl;
}

void Enemy::PrintTargetInfo() {
    cout << "Target: " << _target->GetName() << endl;
    cout << "HP: " << _target->GetHitpoints() << endl;
}

int main() {
    Hero wolverine("Wolverine", 50, 60);
    Hero cyclops("Cyclops", 30, 80);

    Enemy sentinel;
    sentinel.SetTarget(&wolverine);
    sentinel.PrintTargetInfo();

    wolverine.TakeDamage(20);
    sentinel.PrintTargetInfo();

    sentinel.SetTarget(&cyclops);
    sentinel.PrintTargetInfo();

    sentinel.SetTarget(nullptr);


    return 0;
}
