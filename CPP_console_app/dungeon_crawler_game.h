#ifndef DUNGEON_CRAWLER_GAME_H
#define DUNGEON_CRAWLER_GAME_H

#include "game_utils.h"
#include "Character.h"
#include "Shop.h"

class DungeonCrawlerGame {
private:
    mt19937 rng;
    string playerName;
    int level;
    int gold;

    // inventory / equipment were moved into Character

    // quest items / chapter items
    bool hasEyeJewel;
    bool hasSpiralStone;
    bool hasParchmentPiece1;
    bool hasParchmentPiece2;
    bool acceptedGoblinQuest;
    bool completedGoblinQuest;
    bool engagedHoodedFigure;
    
    void displayWelcome();
    
public:
    DungeonCrawlerGame(const string& name);
    void run();
};

#endif // DUNGEON_CRAWLER_GAME_H