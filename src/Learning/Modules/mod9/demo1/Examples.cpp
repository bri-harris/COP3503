#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include "Hero.h"
using namespace std;


//Wizard.h
class Wizard : virtual public Hero //wizard IS - A Hero
{
    int _mana; // Magic
    int _maxMana; // Magic

public:
    Wizard(string name = "Bob", int strength = 10, int hitpoints = 25, int mana = 100);
    void PrintInfo(bool verbose = false) const;
    void TakeDamage(int amount);

    //unique wizard behaviors
    void Fireball(Hero& target) {
        target.TakeDamage(50 + _mana);
    }
    void Fly();
    void Invisibility();
    int GetPowerLevel() const;
};

//wizard.cpp
Wizard::Wizard(string name, int strength, int hitpoints, int mana)
    : _mana(mana), Hero(name, strength, hitpoints) {
    _maxMana = mana;
}
void Wizard::PrintInfo(bool verbose) const {
    Hero::PrintInfo();
    cout << "Mana: " << _mana << "/" << _maxMana << endl;
}
void Wizard::TakeDamage(int amount) {
    int damageAbsorbed = 0;
    if (_mana >= amount) {
        damageAbsorbed = amount;
        _mana -= amount;
        cout << GetName() << " absorbs " << damageAbsorbed << " damage with a magical barrier!" << endl;

        amount = 0;
    } else if (_mana < amount) {
        damageAbsorbed = _mana;
        cout << GetName() << "'s magical barrier absorbed " << damageAbsorbed << " damage & then broke." << endl;
        amount -= _mana;
        _mana = 0;
    }
    Hero::TakeDamage(amount);
}
int Wizard::GetPowerLevel() const {
    return GetLevel() * 5 + _mana / 20;
}

//Fighter.h
class Fighter : virtual public Hero {
    int _fury; // fight for longer get angrier
    int _maxFury; //Fight for longer get angrieir

public:
    Fighter(string name = "Bob", int strength = 10, int hitpoints = 25);
    void FuriousStrike(Hero& target);
    void PrintInfo(bool verbose = false) const;
    void BodySlam(Hero& target);
    void TakeDamage(int amount);
    int GetPowerLevel() const;
};

//Fighter.cpp
Fighter::Fighter(string name, int strength, int hitpoints)
    : Hero(name, strength, hitpoints), _fury(0), _maxFury(100) {
}
void Fighter::PrintInfo(bool verbose) const {
    Hero::PrintInfo(verbose);
    cout << "Fury: " << _fury << "/" << _maxFury << endl;
}
void Fighter::TakeDamage(int amount) {
    Hero::TakeDamage(amount);

    int furyGained = amount * 0.5f;
    cout << GetName() << " gains " << furyGained << " fury! ";
    _fury += furyGained;
    if (_fury > _maxFury)
        _fury = _maxFury;
    float furyRatio = (float) _fury / _maxFury;
    if (furyRatio > 0.8f)
        cout << GetName() << " is furious!" << endl;
    else if (furyRatio > 0.5f)
        cout << GetName() << " is heating up!" << endl;
    else if (furyRatio > 0.25f)
        cout << GetName() << " is starting to get angry..." << endl;
}
int Fighter::GetPowerLevel() const {
    return GetLevel() * 5 + GetStrength() * 3;
}

int main() {
    vector<Hero*> heroes;
    heroes.push_back(new Wizard("Merlin", 15, 70, 250));
    heroes.push_back(new Fighter("Conan", 80, 350));

    cout << "Heros are dealt 100 damage... \n";
    for (unsigned int i = 0; i < heroes.size(); i++)
        heroes[i]->TakeDamage(100);

    cout << endl;
    for (unsigned int i = 0; i < heroes.size(); i++)
        heroes[i]->PrintInfo();

    cout << endl;
    for (unsigned int i = 0; i < heroes.size(); i++)
        heroes[i]->TakeDamage(175);

    cout << endl;
    for (unsigned int i = 0; i < heroes.size(); i++)
        heroes[i]->PrintInfo();


    for (unsigned int i = 0; i < heroes.size(); i++)
        delete heroes[i];

    return 0;
}

