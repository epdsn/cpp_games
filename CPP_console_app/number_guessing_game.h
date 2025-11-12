#ifndef NUMBER_GUESSING_GAME_H
#define NUMBER_GUESSING_GAME_H

#include "game_utils.h"

class NumberGuessingGame {
private:
    mt19937 rng;
    
public:
    NumberGuessingGame();
    void run();
};

#endif // NUMBER_GUESSING_GAME_H