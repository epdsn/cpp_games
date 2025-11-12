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
    
    void displayWelcome();
    void chooseClass();
    void chooseWeapon();
    void allocateStatPoints();
    void displayCharacterSheet();
    
public:
    DungeonCrawlerGame(const string& name);
    void run();
};

#endif // DUNGEON_CRAWLER_GAME_H