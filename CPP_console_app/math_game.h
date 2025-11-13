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
    
    // 4th grade level methods
    void playDecimalRound();
    void playWordProblemRound();
    pair<double, double> generateDecimals();
    double calculateDecimalAnswer(double num1, double num2, char op);
    void generateWordProblem(string& problem, int& answer);
    bool isCorrectDecimal(double userAnswer, double correctAnswer);
    
    // Algebra methods
    void playAlgebraRound();
    void generateAlgebraProblem(string& equation, int& answer);
    void generateLinearEquation(string& equation, int& answer);
    void generateSimpleEquation(string& equation, int& answer);
    
public:
    MathGame();
    void run();
};

#endif // MATH_GAME_H