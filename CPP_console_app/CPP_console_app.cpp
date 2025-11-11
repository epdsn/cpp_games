#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include <iomanip>
#include <cstdlib>

using namespace std;

class NumberGuessingGame {
private:
    mt19937 rng;
    string playerName;
    
public:
    NumberGuessingGame() : rng(time(nullptr)) {}
    
    void run() {
        cout << "\n### WELCOME TO NUMBER GUESSING GAME! ###" << endl;
        cout << "=======================================" << endl;
        cout << "I'm thinking of a number between 1 and 100." << endl;
        cout << "Can you guess it?" << endl << endl;
        
        uniform_int_distribution<int> dist(1, 100);
        int secretNumber = dist(rng);
        int guess;
        int attempts = 0;
        
        do {
            cout << "Enter your guess (1-100): ";
            cin >> guess;
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
};

class MathGame {
private:
    int score;
    int totalQuestions;
    int correctAnswers;
    mt19937 rng;
    
public:
    MathGame() : score(0), totalQuestions(0), correctAnswers(0), rng(time(nullptr)) {}
    
    void displayWelcome() {
        cout << "\n### WELCOME TO MATH MASTER! ###" << endl;
        cout << "===============================" << endl;
        cout << "Test your math skills and become a Math Master!" << endl;
        cout << "You'll earn points for correct answers!" << endl;
        cout << "===============================" << endl << endl;
    }
    
    void displayMenu() {
        cout << "\n### Choose your challenge:" << endl;
        cout << "1. Easy (Addition & Subtraction, 1-20)" << endl;
        cout << "2. Medium (All operations, 1-50)" << endl;
        cout << "3. Hard (All operations, 1-100)" << endl;
        cout << "4. View Statistics" << endl;
        cout << "5. Return to Main Menu" << endl;
        cout << "Enter your choice (1-5): ";
    }
    
    pair<int, int> generateNumbers(int difficulty) {
        uniform_int_distribution<int> dist;
        
        switch(difficulty) {
            case 1: dist = uniform_int_distribution<int>(1, 20); break;
            case 2: dist = uniform_int_distribution<int>(1, 50); break;
            case 3: dist = uniform_int_distribution<int>(1, 100); break;
            default: dist = uniform_int_distribution<int>(1, 20); break;
        }
        
        return {dist(rng), dist(rng)};
    }
    
    char getOperation(int difficulty) {
        vector<char> operations;
        
        if (difficulty == 1) {
            operations = {'+', '-'};
        } else {
            operations = {'+', '-', '*', '/'};
        }
        
        uniform_int_distribution<int> opDist(0, operations.size() - 1);
        return operations[opDist(rng)];
    }
    
    int calculateAnswer(int num1, int num2, char op) {
        switch(op) {
            case '+': return num1 + num2;
            case '-': return num1 - num2;
            case '*': return num1 * num2;
            case '/': return num1 / num2;
            default: return 0;
        }
    }
    
    void playRound(int difficulty) {
        const int questionsPerRound = 5;
        int roundScore = 0;
        
        cout << "\n### Starting Round - Answer " << questionsPerRound << " questions!" << endl;
        cout << "===========================================" << endl;
        
        for (int i = 1; i <= questionsPerRound; i++) {
            pair<int, int> numbers = generateNumbers(difficulty);
            int num1 = numbers.first;
            int num2 = numbers.second;
            char operation = getOperation(difficulty);
            
            // For division, make sure we get whole number results
            if (operation == '/') {
                num1 = num2 * uniform_int_distribution<int>(1, 10)(rng);
            }
            
            // For subtraction, make sure result is positive
            if (operation == '-' && num2 > num1) {
                swap(num1, num2);
            }
            
            int correctAnswer = calculateAnswer(num1, num2, operation);
            
            cout << "\nQuestion " << i << ": ";
            cout << num1 << " " << operation << " " << num2 << " = ? ";
            
            int userAnswer;
            cin >> userAnswer;
            
            totalQuestions++;
            
            if (userAnswer == correctAnswer) {
                cout << "### Correct! ";
                correctAnswers++;
                int points = difficulty * 10;
                roundScore += points;
                score += points;
                cout << "+" << points << " points!" << endl;
            } else {
                cout << "### Wrong! The correct answer is " << correctAnswer << endl;
            }
        }
        
        cout << "\n### Round Complete!" << endl;
        cout << "Round Score: " << roundScore << " points" << endl;
        cout << "Total Score: " << score << " points" << endl;
    }
    
    void displayStats() {
        cout << "\n### YOUR STATISTICS" << endl;
        cout << "===================" << endl;
        cout << "Total Score: " << score << " points" << endl;
        cout << "Questions Answered: " << totalQuestions << endl;
        cout << "Correct Answers: " << correctAnswers << endl;
        
        if (totalQuestions > 0) {
            double accuracy = (double(correctAnswers) / totalQuestions) * 100;
            cout << "Accuracy: " << fixed << setprecision(1) << accuracy << "%" << endl;
            
            cout << "Rank: ";
            if (accuracy >= 90) cout << "### Math Master!" << endl;
            else if (accuracy >= 80) cout << "#1# Math Expert!" << endl;
            else if (accuracy >= 70) cout << "#2# Math Scholar!" << endl;
            else if (accuracy >= 60) cout << "#3# Math Student!" << endl;
            else cout << "### Keep Practicing!" << endl;
        }
    }
    
    void run() {
        displayWelcome();
        
        int choice;
        do {
            displayMenu();
            cin >> choice;
            
            switch (choice) {
                case 1:
                case 2:
                case 3:
                    playRound(choice);
                    break;
                case 4:
                    displayStats();
                    break;
                case 5:
                    cout << "\n### Thanks for playing Math Master!" << endl;
                    displayStats();
                    return; // Return to main menu
                default:
                    cout << "### Invalid choice! Please enter 1-5." << endl;
            }
        } while (choice != 5);
    }
};

class DungeonCrawlerGame {
private:
    mt19937 rng;
    string playerName;
    
    // Character stats and info
    string characterClass;
    string weapon;
    int strength;
    int magic;
    int health;
    int maxHealth;
    int level;
    int gold;
    
public:
    DungeonCrawlerGame(const string& name) : 
        rng(time(nullptr)), 
        playerName(name), 
        strength(0), 
        magic(0), 
        health(100), 
        maxHealth(100),
        level(1),
        gold(50) {}
    
    void displayWelcome() {
        cout << "\n### WELCOME TO DUNGEON CRAWLER, " << playerName << "! ###" << endl;
        cout << "===============================================" << endl;
        cout << "### Prepare to explore dangerous dungeons!" << endl;
        cout << "### Battle monsters and collect treasure!" << endl;
        cout << "### Your choices will determine your fate!" << endl;
        cout << "===============================================" << endl << endl;
    }
    
    void chooseClass() {
        cout << "### Choose Your Character Class ###" << endl;
        cout << "==================================" << endl;
        cout << "1. ### Warrior   - High strength, low magic" << endl;
        cout << "2. ### Mage      - High magic, low strength" << endl;
        cout << "3. ### Paladin   - Balanced strength and magic" << endl;
        cout << "4. ### Ranger    - Medium strength, medium magic" << endl;
        cout << "Enter your choice (1-4): ";
        
        int classChoice;
        cin >> classChoice;
        
        switch (classChoice) {
            case 1:
                characterClass = "Warrior";
                strength = 15;
                magic = 5;
                cout << "\n### You chose Warrior! Masters of combat and strength!" << endl;
                break;
            case 2:
                characterClass = "Mage";
                strength = 5;
                magic = 15;
                cout << "\n### You chose Mage! Wielders of powerful magic!" << endl;
                break;
            case 3:
                characterClass = "Paladin";
                strength = 10;
                magic = 10;
                cout << "\n### You chose Paladin! Holy warriors with balanced abilities!" << endl;
                break;
            case 4:
                characterClass = "Ranger";
                strength = 8;
                magic = 7;
                cout << "\n### You chose Ranger! Swift and versatile adventurers!" << endl;
                break;
            default:
                characterClass = "Warrior";
                strength = 15;
                magic = 5;
                cout << "\n### Invalid choice! Defaulting to Warrior!" << endl;
                break;
        }
        cout << "Base Stats - Strength: " << strength << ", Magic: " << magic << endl;
    }
    
    void chooseWeapon() {
        cout << "\n### Choose Your Starting Weapon ###" << endl;
        cout << "===================================" << endl;
        
        if (characterClass == "Warrior") {
            cout << "1. ### Iron Sword    (+3 Strength)" << endl;
            cout << "2. ### War Hammer    (+4 Strength, -1 Magic)" << endl;
            cout << "3. ### Sword & Shield (+2 Strength, +1 Health)" << endl;
        }
        else if (characterClass == "Mage") {
            cout << "1. ### Crystal Staff  (+3 Magic)" << endl;
            cout << "2. ### Spell Tome    (+4 Magic, -1 Strength)" << endl;
            cout << "3. ### Lightning Wand (+2 Magic, +1 Health)" << endl;
        }
        else if (characterClass == "Paladin") {
            cout << "1. ### Holy Blade    (+2 Strength, +1 Magic)" << endl;
            cout << "2. ### Divine Mace   (+2 Strength, +2 Magic)" << endl;
            cout << "3. ### Sacred Shield (+1 Strength, +1 Magic, +2 Health)" << endl;
        }
        else { // Ranger
            cout << "1. ### Elven Bow     (+2 Strength, +1 Magic)" << endl;
            cout << "2. ### Twin Blades   (+3 Strength)" << endl;
            cout << "3. ### Crossbow      (+2 Strength, +1 Health)" << endl;
        }
        cout << "Enter your choice (1-3): ";
        
        int weaponChoice;
        cin >> weaponChoice;
        
        if (characterClass == "Warrior") {
            switch (weaponChoice) {
                case 1: weapon = "Iron Sword"; strength += 3; break;
                case 2: weapon = "War Hammer"; strength += 4; magic -= 1; break;
                case 3: weapon = "Sword & Shield"; strength += 2; health += 10; maxHealth += 10; break;
                default: weapon = "Iron Sword"; strength += 3; break;
            }
        }
        else if (characterClass == "Mage") {
            switch (weaponChoice) {
                case 1: weapon = "Crystal Staff"; magic += 3; break;
                case 2: weapon = "Spell Tome"; magic += 4; strength -= 1; break;
                case 3: weapon = "Lightning Wand"; magic += 2; health += 10; maxHealth += 10; break;
                default: weapon = "Crystal Staff"; magic += 3; break;
            }
        }
        else if (characterClass == "Paladin") {
            switch (weaponChoice) {
                case 1: weapon = "Holy Blade"; strength += 2; magic += 1; break;
                case 2: weapon = "Divine Mace"; strength += 2; magic += 2; break;
                case 3: weapon = "Sacred Shield"; strength += 1; magic += 1; health += 20; maxHealth += 20; break;
                default: weapon = "Holy Blade"; strength += 2; magic += 1; break;
            }
        }
        else { // Ranger
            switch (weaponChoice) {
                case 1: weapon = "Elven Bow"; strength += 2; magic += 1; break;
                case 2: weapon = "Twin Blades"; strength += 3; break;
                case 3: weapon = "Crossbow"; strength += 2; health += 10; maxHealth += 10; break;
                default: weapon = "Elven Bow"; strength += 2; magic += 1; break;
            }
        }
        
        cout << "\n### You equipped: " << weapon << "!" << endl;
        cout << "Updated Stats - Strength: " << strength << ", Magic: " << magic << ", Health: " << health << endl;
    }
    
    void allocateStatPoints() {
        const int totalPoints = 10;
        int remainingPoints = totalPoints;
        
        cout << "\n### Allocate Bonus Stat Points ###" << endl;
        cout << "==================================" << endl;
        cout << "You have " << totalPoints << " bonus points to distribute!" << endl;
        cout << "Current Stats - Strength: " << strength << ", Magic: " << magic << endl;
        
        while (remainingPoints > 0) {
            cout << "\nRemaining points: " << remainingPoints << endl;
            cout << "1. Add to Strength (current: " << strength << ")" << endl;
            cout << "2. Add to Magic (current: " << magic << ")" << endl;
            cout << "3. Finish allocation" << endl;
            cout << "Choose where to add a point: ";
            
            int choice;
            cin >> choice;
            
            switch (choice) {
                case 1:
                    if (remainingPoints > 0) {
                        strength++;
                        remainingPoints--;
                        cout << "### Added 1 point to Strength! (Now: " << strength << ")" << endl;
                    }
                    break;
                case 2:
                    if (remainingPoints > 0) {
                        magic++;
                        remainingPoints--;
                        cout << "### Added 1 point to Magic! (Now: " << magic << ")" << endl;
                    }
                    break;
                case 3:
                    cout << "Finishing with " << remainingPoints << " unused points." << endl;
                    remainingPoints = 0;
                    break;
                default:
                    cout << "### Invalid choice!" << endl;
                    break;
            }
        }
        
        cout << "\n### Stat Allocation Complete! ###" << endl;
    }
    
    void displayCharacterSheet() {
        cout << "\n############################################" << endl;
        cout << "###        CHARACTER SHEET               ###" << endl;
        cout << "############################################" << endl;
        cout << "### Name: " << playerName << endl;
        cout << "### Class: " << characterClass << endl;
        cout << "### Weapon: " << weapon << endl;
        cout << "### Strength: " << strength << endl;
        cout << "### Magic: " << magic << endl;
        cout << "### Health: " << health << "/" << maxHealth << endl;
        cout << "### Level: " << level << endl;
        cout << "### Gold: " << gold << endl;
        cout << "############################################" << endl;
        
        cout << "\n### " << playerName << " the " << characterClass << " is ready for adventure!" << endl;
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
    }
    
    void run() {
        displayWelcome();
        chooseClass();
        chooseWeapon();
        allocateStatPoints();
        displayCharacterSheet();
        
        cout << "\n### Adventure awaits! Character creation complete!" << endl;
        cout << "### (Dungeon exploration features coming soon!)" << endl;
        cout << "Press Enter to return to main menu...";
        cin.ignore();
        cin.get();
    }
};

void displayMainMenu() {
    cout << "\n=================================================" << endl;
    cout << "          ### WELCOME TO GAME CENTER! ###         " << endl;
    cout << "=================================================" << endl;
    cout << "Choose which game you'd like to play:" << endl;
    cout << "1. Number Guessing Game" << endl;
    cout << "2. Math Master Game" << endl;
    cout << "3. Dungeon Crawler Game" << endl;
    cout << "4. Quit" << endl;
    cout << "=================================================" << endl;
    cout << "Enter your choice (1-4): ";
}

int main()
{
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
            case 4:
                cout << "\n### Thanks for playing, " << playerName << "! See you next time! ###" << endl;
                cout << "Have a great day! :)" << endl;
                break;
            default:
                cout << "X Invalid choice! Please enter 1, 2, 3, or 4." << endl;
        }
        
        cout << endl;
        
    } while (mainChoice != 4);
    
    return 0;
}