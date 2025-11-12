#include "math_game.h"

MathGame::MathGame() : score(0), totalQuestions(0), correctAnswers(0), rng(time(nullptr)) {}

void MathGame::displayWelcome() {
    cout << "\n### WELCOME TO MATH MASTER! ###" << endl;
    cout << "===============================" << endl;
    cout << "Test your math skills and become a Math Master!" << endl;
    cout << "You'll earn points for correct answers!" << endl;
    cout << "===============================" << endl << endl;
}

void MathGame::displayMenu() {
    cout << "\n### Choose your challenge:" << endl;
    cout << "1. Easy (Addition & Subtraction, 1-20)" << endl;
    cout << "2. Medium (All operations, 1-50)" << endl;
    cout << "3. Hard (All operations, 1-100)" << endl;
    cout << "4. View Statistics" << endl;
    cout << "5. Return to Main Menu" << endl;
    cout << "Enter your choice (1-5): ";
}

pair<int, int> MathGame::generateNumbers(int difficulty) {
    uniform_int_distribution<int> dist;
    
    switch(difficulty) {
        case 1: dist = uniform_int_distribution<int>(1, 20); break;
        case 2: dist = uniform_int_distribution<int>(1, 50); break;
        case 3: dist = uniform_int_distribution<int>(1, 100); break;
        default: dist = uniform_int_distribution<int>(1, 20); break;
    }
    
    return {dist(rng), dist(rng)};
}

char MathGame::getOperation(int difficulty) {
    vector<char> operations;
    
    if (difficulty == 1) {
        operations = {'+', '-'};
    } else {
        operations = {'+', '-', '*', '/'};
    }
    
    uniform_int_distribution<int> opDist(0, operations.size() - 1);
    return operations[opDist(rng)];
}

int MathGame::calculateAnswer(int num1, int num2, char op) {
    switch(op) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return num1 / num2;
        default: return 0;
    }
}

void MathGame::playRound(int difficulty) {
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

void MathGame::displayStats() {
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

void MathGame::run() {
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
                return;
            default:
                cout << "### Invalid choice! Please enter 1-5." << endl;
        }
    } while (choice != 5);
}