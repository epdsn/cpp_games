#include "Character.h"
#include <iostream>
#include <limits>

using namespace std;

Character::Character()
    : characterClass("Warrior"), weapon("None"), strength(0), magic(0), health(100), maxHealth(100), armor(0), healthPotions(0), manaPotions(0) {}

void Character::chooseClass() {
    cout << "\n### Choose Your Character Class ###" << endl;
    cout << "1. Warrior  2. Mage  3. Paladin  4. Ranger" << endl;
    int c = 1;
    if (!(cin >> c)) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); c = 1; }
    switch (c) {
        case 1: characterClass = "Warrior"; strength = 15; magic = 5; break;
        case 2: characterClass = "Mage"; strength = 5; magic = 15; break;
        case 3: characterClass = "Paladin"; strength = 10; magic = 10; break;
        case 4: characterClass = "Ranger"; strength = 8; magic = 7; break;
        default: characterClass = "Warrior"; strength = 15; magic = 5; break;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Character::chooseWeapon() {
    cout << "\n### Choose Weapon for " << characterClass << " ###" << endl;
    if (characterClass == "Warrior") {
        cout << "1. Iron Sword 2. War Hammer 3. Sword & Shield" << endl;
    } else if (characterClass == "Mage") {
        cout << "1. Crystal Staff 2. Spell Tome 3. Lightning Wand" << endl;
    } else if (characterClass == "Paladin") {
        cout << "1. Holy Blade 2. Divine Mace 3. Sacred Shield" << endl;
    } else {
        cout << "1. Elven Bow 2. Twin Blades 3. Crossbow" << endl;
    }
    int w = 1;
    if (!(cin >> w)) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); w = 1; }

    // apply simple effects
    if (characterClass == "Warrior") {
        switch (w) {
            case 1: weapon = "Iron Sword"; strength += 3; break;
            case 2: weapon = "War Hammer"; strength += 4; magic -= 1; break;
            case 3: weapon = "Sword & Shield"; strength += 2; health += 10; maxHealth += 10; break;
            default: weapon = "Iron Sword"; strength += 3; break;
        }
    } else if (characterClass == "Mage") {
        switch (w) {
            case 1: weapon = "Crystal Staff"; magic += 3; break;
            case 2: weapon = "Spell Tome"; magic += 4; strength -= 1; break;
            case 3: weapon = "Lightning Wand"; magic += 2; health += 10; maxHealth += 10; break;
            default: weapon = "Crystal Staff"; magic += 3; break;
        }
    } else if (characterClass == "Paladin") {
        switch (w) {
            case 1: weapon = "Holy Blade"; strength += 2; magic += 1; break;
            case 2: weapon = "Divine Mace"; strength += 2; magic += 2; break;
            case 3: weapon = "Sacred Shield"; strength += 1; magic += 1; health += 20; maxHealth += 20; break;
            default: weapon = "Holy Blade"; strength += 2; magic += 1; break;
        }
    } else {
        switch (w) {
            case 1: weapon = "Elven Bow"; strength += 2; magic += 1; break;
            case 2: weapon = "Twin Blades"; strength += 3; break;
            case 3: weapon = "Crossbow"; strength += 2; health += 10; maxHealth += 10; break;
            default: weapon = "Elven Bow"; strength += 2; magic += 1; break;
        }
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Character::allocateStatPoints() {
    const int total = 10;
    int remaining = total;
    while (remaining > 0) {
        cout << "\nRemaining: " << remaining << " 1) Strength 2) Magic 3) Finish: ";
        int c = 3;
        if (!(cin >> c)) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); c = 3; }
        if (c == 1) { strength++; remaining--; cout << "Added to Strength."; }
        else if (c == 2) { magic++; remaining--; cout << "Added to Magic."; }
        else break;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Character::displayCharacterSheet(const string& playerName) const {
    cout << "\n### CHARACTER SHEET ###" << endl;
    cout << "Name: " << playerName << endl;
    cout << "Class: " << characterClass << " Weapon: " << weapon << endl;
    cout << "Strength: " << strength << " Magic: " << magic << endl;
    cout << "Health: " << health << "/" << maxHealth << " Armor: " << armor << endl;
    cout << "Health Potions: " << healthPotions << " Mana Potions: " << manaPotions << endl;
    cout << "Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
