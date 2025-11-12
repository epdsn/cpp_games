#ifndef WORDLE_GAME_H
#define WORDLE_GAME_H

#include "game_utils.h"

class WordleGame {
private:
    mt19937 rng;
    vector<string> wordList;
    string secretWord;
    int attempts;
    int maxAttempts;
    
    void initializeWordList();
    string selectRandomWord();
    bool isValidGuess(const string& guess);
    string toUpperCase(const string& str);
    void displayBoard(const vector<string>& guesses, const vector<vector<int>>& feedback);
    vector<int> checkGuess(const string& guess);
    void displayWelcome();
    
public:
    WordleGame();
    void run();
};

#endif // WORDLE_GAME_H

