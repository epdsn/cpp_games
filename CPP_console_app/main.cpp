#include "game_utils.h"
#include "number_guessing_game.h"
#include "math_game.h"
#include "dungeon_crawler_game.h"
#include "wordle_game.h"

void displayMainMenu() {
    cout << "\n=================================================" << endl;
    cout << "          ### WELCOME TO GAME CENTER! ###         " << endl;
    cout << "=================================================" << endl;
    cout << "Choose which game you'd like to play:" << endl;
    cout << "1. Number Guessing Game" << endl;
    cout << "2. Math Master Game" << endl;
    cout << "3. Dungeon Crawler Game" << endl;
    cout << "4. Wordle Game" << endl;
    cout << "5. Quit" << endl;
    cout << "=================================================" << endl;
    cout << "Enter your choice (1-5): ";
}

int main() {
    int mainChoice;
    string playerName;
    
    cout << "### Welcome to the Ultimate Game Collection! ###" << endl;
    cout << "===============================================" << endl;
    cout << "What is your name: ";
    cin >> playerName;
    if (playerName.empty()) {
        playerName = "Player";
    }

    cout << "Hello, " << playerName << "! Get ready for some fun!" << endl;
    
    do {
        displayMainMenu();
        cin >> mainChoice;
        
        switch (mainChoice) {
            case 1: {
                NumberGuessingGame guessingGame;
                guessingGame.run();
                break;
            }
            case 2: {
                MathGame mathGame;
                mathGame.run();
                break;
            }
            case 3: {
                DungeonCrawlerGame dungeonGame(playerName);
                dungeonGame.run();
                break;
            }
            case 4: {
                WordleGame wordleGame;
                wordleGame.run();
                break;
            }
            case 5:
                cout << "\n### Thanks for playing, " << playerName << "! See you next time! ###" << endl;
                cout << "Have a great day! :)" << endl;
                break;
            default:
                cout << "X Invalid choice! Please enter 1, 2, 3, 4, or 5." << endl;
        }
        
        cout << endl;
        
    } while (mainChoice != 5);
    
    return 0;
}