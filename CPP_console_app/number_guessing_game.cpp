#include "number_guessing_game.h"

NumberGuessingGame::NumberGuessingGame() : rng(time(nullptr)) {}

void NumberGuessingGame::run() {
    cout << "\n### WELCOME TO NUMBER GUESSING GAME! ###" << endl;
    cout << "=======================================" << endl;
    cout << "I'm thinking of a number between 1 and 100." << endl;
    cout << "Can you guess it?" << endl;
    cout << "(Enter 0 to quit)" << endl << endl;
    
    uniform_int_distribution<int> dist(1, 100);
    int secretNumber = dist(rng);
    int guess;
    int attempts = 0;
    
    do {
        cout << "Enter your guess (1-100, or 0 to quit): ";
        cin >> guess;
        
        if (guess == 0) {
            cout << "\n### Quitting game. The number was: " << secretNumber << endl;
            cout << "Thanks for playing the Number Guessing Game!" << endl;
            return;
        }
        
        attempts++;
        
        if (guess == secretNumber) {
            cout << "### Congratulations! You guessed it!" << endl;
            cout << "It took you " << attempts << " attempt(s)." << endl;
            
            if (attempts <= 5) cout << "### Amazing! You're a guessing master!" << endl;
            else if (attempts <= 10) cout << "### Great job! Excellent guessing!" << endl;
            else if (attempts <= 15) cout << "### Good work! Nice guessing!" << endl;
            else cout << "### You got it! Keep practicing!" << endl;
        }
        else if (guess > secretNumber) {
            cout << "/\\ Too high! Try a lower number." << endl;
        }
        else {
            cout << "\\/ Too low! Try a higher number." << endl;
        }
        
        cout << endl;
        
    } while (guess != secretNumber);
    
    cout << "Thanks for playing the Number Guessing Game!" << endl;
}