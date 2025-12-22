#include "Shop.h"
#include <iostream>
#include <string>

using namespace std;

void Shop::visit(Character& player, int& gold) {
    cout << "\n### TOWN SHOP ###" << endl;
    cout << "You have " << gold << " gold." << endl;
    cout << "1) Leather Armor (+10 max health) - 25 gold" << endl;
    cout << "2) Iron Armor (+25 max health) - 50 gold" << endl;
    cout << "3) Health Potion - 10 gold" << endl;
    cout << "4) Mana Potion - 8 gold" << endl;
    cout << "5) Leave" << endl;

    string line;
    while (true) {
        cout << "Enter choice (1-5): ";
        if (!getline(cin, line)) return;
        if (line.empty()) continue;
        int choice = 0;
        try { choice = stoi(line); } catch (...) { cout << "Invalid input." << endl; continue; }
        switch (choice) {
            case 1:
                if (gold >= 25) { gold -= 25; player.armor += 10; player.maxHealth += 10; player.health += 10; cout << "Leather armor purchased." << endl; }
                else cout << "Not enough gold." << endl;
                break;
            case 2:
                if (gold >= 50) { gold -= 50; player.armor += 25; player.maxHealth += 25; player.health += 25; cout << "Iron armor purchased." << endl; }
                else cout << "Not enough gold." << endl;
                break;
            case 3:
                if (gold >= 10) { gold -= 10; player.healthPotions++; cout << "Health potion purchased." << endl; }
                else cout << "Not enough gold." << endl;
                break;
            case 4:
                if (gold >= 8) { gold -= 8; player.manaPotions++; cout << "Mana potion purchased." << endl; }
                else cout << "Not enough gold." << endl;
                break;
            case 5:
                cout << "Leaving shop." << endl;
                return;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    }
}
