#ifndef MATH_GAME_H
#define MATH_GAME_H

#include "game_utils.h"

class MathGame {
private:
    int score;
    int totalQuestions;
    int correctAnswers;
    mt19937 rng;
    
    void displayWelcome();
    void displayMenu();
    pair<int, int> generateNumbers(int difficulty);
    char getOperation(int difficulty);
    int calculateAnswer(int num1, int num2, char op);
    void playRound(int difficulty);
    void displayStats();
    
public:
    MathGame();
    void run();
};

#endif // MATH_GAME_H