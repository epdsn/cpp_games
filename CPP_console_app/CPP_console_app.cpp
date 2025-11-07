#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;


int main()
{
    srand(time(0));
    //int rando = rand() % 11;

    //cout << "Hello World!" << endl;
    //cout << "The number is : " << rando << endl;
    //return 0;

    int secretNumber = rand() % 11;

    int guess;
    int attempts = 0;

    cout << "=== Number Guessing Game ===" << endl;
    cout << "I'm thinking of a number between 0 and 10." << endl;
    cout << "Can you guess it?" << endl << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;  // Get input from user and store it in 'guess' variable
        attempts++;    // Increment attempt counter (same as attempts = attempts + 1)

        // Check if the guess is correct, too high, or too low
        if (guess == secretNumber) {
            // User guessed correctly!
            cout << "Congratulations! You guessed it!" << endl;
            cout << "It took you " << attempts << " attempt(s)." << endl;
        }
        else if (guess > secretNumber) {
            // Guess is too high - give feedback
            cout << "Too high! Try again." << endl;
        }
        else {
            // Guess is too low (this is the only other possibility)
            cout << "Too low! Try again." << endl;
        }

        cout << endl;  // Add a blank line for readability

    } while (guess != secretNumber);  // Continue loop while guess is NOT equal to secretNumber

    // Game over message
    cout << "Thanks for playing!" << endl;

    return 0;  // Return 0 indicates the program ran successfully

}