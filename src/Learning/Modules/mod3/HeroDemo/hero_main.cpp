#include <string>
#include <iostream>
#include <vector>
#include "Hero.h"
using namespace std;

// class Enemy {
//     Hero *_target;
//
// public:
//     void SetTarget(Hero *target);
//
//     void PrintTargetInfo();
// };
//
// void Enemy::SetTarget(Hero *target) {
//     cout << "Target set to " << target->GetName() << endl;
//     _target = target;
// }
//
// void Enemy::PrintTargetInfo() {
//     cout << "Target: " << _target->GetName() << endl;
//     cout << "HP: " << _target->GetHitpoints() << endl;
// }

// int main() {
//     Hero wolverine("Wolverine", 50, 60);
//     Hero cyclops("Cyclops", 30, 80);
//
//     Enemy sentinel;
//     sentinel.SetTarget(&wolverine);
//     sentinel.PrintTargetInfo();
//     wolverine.TakeDamage(15);
//     sentinel.PrintTargetInfo();
//
//     sentinel.SetTarget(&cyclops);
//     sentinel.SetTarget(nullptr);
//
//     return 0;
// }
