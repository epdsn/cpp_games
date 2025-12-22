#pragma once
#include <string>

struct Character {
    std::string characterClass;
    std::string weapon;
    int strength;
    int magic;
    int health;
    int maxHealth;
    int armor;
    int healthPotions;
    int manaPotions;

    Character();

    void chooseClass();
    void chooseWeapon();
    void allocateStatPoints();
    void displayCharacterSheet(const std::string& playerName) const;
};
