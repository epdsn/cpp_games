#ifndef DUNGEON_CRAWLER_GAME_H
#define DUNGEON_CRAWLER_GAME_H

#include "game_utils.h"

class DungeonCrawlerGame {
private:
    mt19937 rng;
    string playerName;
    string characterClass;
    string weapon;
    int strength;
    int magic;
    int health;
    int maxHealth;
    int level;
    int gold;

    // inventory / equipment
    int armor; // additional armor value (increases maxHealth)
    int healthPotions; // count of health potions
    int manaPotions; // count of mana potions

    // quest items / chapter items
    bool hasEyeJewel;
    bool hasSpiralStone;
    bool hasParchmentPiece1;
    bool hasParchmentPiece2;
    bool acceptedGoblinQuest;
    bool completedGoblinQuest;
    bool engagedHoodedFigure;
    
    void displayWelcome();
    void chooseClass();
    void chooseWeapon();
    void allocateStatPoints();
    void displayCharacterSheet();
    void visitShop();
    
public:
    DungeonCrawlerGame(const string& name);
    void run();
};

#endif // DUNGEON_CRAWLER_GAME_H