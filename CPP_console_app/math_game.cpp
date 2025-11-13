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
    cout << "4. 4th Grade Decimals (Addition with decimals)" << endl;
    cout << "5. 4th Grade Word Problems" << endl;
    cout << "6. Algebra (Solve for x)" << endl;
    cout << "7. View Statistics" << endl;
    cout << "8. Return to Main Menu" << endl;
    cout << "Enter your choice (1-8): ";
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
                playDecimalRound();
                break;
            case 5:
                playWordProblemRound();
                break;
            case 6:
                playAlgebraRound();
                break;
            case 7:
                displayStats();
                break;
            case 8:
                cout << "\n### Thanks for playing Math Master!" << endl;
                displayStats();
                return;
            default:
                cout << "### Invalid choice! Please enter 1-8." << endl;
        }
    } while (choice != 8);
}

// 4th Grade Decimal Addition Questions
void MathGame::playDecimalRound() {
    const int questionsPerRound = 5;
    int roundScore = 0;
    
    cout << "\n### 4th Grade Decimal Challenge! ###" << endl;
    cout << "### Adding decimals to one decimal place ###" << endl;
    cout << "==========================================" << endl;
    
    for (int i = 1; i <= questionsPerRound; i++) {
        pair<double, double> numbers = generateDecimals();
        double num1 = numbers.first;
        double num2 = numbers.second;
        
        double correctAnswer = calculateDecimalAnswer(num1, num2, '+');
        
        cout << "\nQuestion " << i << ": ";
        cout << fixed << setprecision(1) << num1 << " + " << num2 << " = ? ";
        
        double userAnswer;
        cin >> userAnswer;
        
        totalQuestions++;
        
        if (isCorrectDecimal(userAnswer, correctAnswer)) {
            cout << "### Correct! ";
            correctAnswers++;
            int points = 15; // Extra points for 4th grade level
            roundScore += points;
            score += points;
            cout << "+" << points << " points!" << endl;
        } else {
            cout << "### Wrong! The correct answer is " << fixed << setprecision(1) << correctAnswer << endl;
        }
    }
    
    cout << "\n### Decimal Round Complete!" << endl;
    cout << "Round Score: " << roundScore << " points" << endl;
    cout << "Total Score: " << score << " points" << endl;
}

// 4th Grade Word Problems
void MathGame::playWordProblemRound() {
    const int questionsPerRound = 3; // Fewer questions since they're more complex
    int roundScore = 0;
    
    cout << "\n### 4th Grade Word Problems! ###" << endl;
    cout << "### Read carefully and solve! ###" << endl;
    cout << "================================" << endl;
    
    for (int i = 1; i <= questionsPerRound; i++) {
        string problem;
        int correctAnswer;
        generateWordProblem(problem, correctAnswer);
        
        cout << "\nWord Problem " << i << ":" << endl;
        cout << problem << endl;
        cout << "Answer: ";
        
        int userAnswer;
        cin >> userAnswer;
        
        totalQuestions++;
        
        if (userAnswer == correctAnswer) {
            cout << "### Excellent reasoning! ";
            correctAnswers++;
            int points = 25; // More points for word problems
            roundScore += points;
            score += points;
            cout << "+" << points << " points!" << endl;
        } else {
            cout << "### Not quite right. The correct answer is " << correctAnswer << endl;
        }
    }
    
    cout << "\n### Word Problem Round Complete!" << endl;
    cout << "Round Score: " << roundScore << " points" << endl;
    cout << "Total Score: " << score << " points" << endl;
}

// Generate decimal numbers for 4th grade level
pair<double, double> MathGame::generateDecimals() {
    uniform_int_distribution<int> whole(1, 20);  // Whole part 1-20
    uniform_int_distribution<int> decimal(1, 9); // Decimal part 0.1-0.9
    
    double num1 = whole(rng) + (decimal(rng) / 10.0);
    double num2 = whole(rng) + (decimal(rng) / 10.0);
    
    return {num1, num2};
}

// Calculate decimal answers
double MathGame::calculateDecimalAnswer(double num1, double num2, char op) {
    switch(op) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        default: return num1 + num2;
    }
}

// Check if decimal answer is correct (with small tolerance for floating point)
bool MathGame::isCorrectDecimal(double userAnswer, double correctAnswer) {
    return abs(userAnswer - correctAnswer) < 0.01;
}

// Generate age-appropriate word problems
void MathGame::generateWordProblem(string& problem, int& answer) {
    uniform_int_distribution<int> problemType(1, 6);
    uniform_int_distribution<int> smallNum(2, 15);
    uniform_int_distribution<int> mediumNum(10, 50);
    
    int type = problemType(rng);
    
    switch(type) {
        case 1: {
            int bags = smallNum(rng);
            int applesPerBag = smallNum(rng);
            answer = bags * applesPerBag;
            problem = "Sarah has " + to_string(bags) + " bags of apples. Each bag contains " + 
                     to_string(applesPerBag) + " apples. How many apples does Sarah have in total?";
            break;
        }
        case 2: {
            int total = mediumNum(rng);
            int given = smallNum(rng);
            answer = total - given;
            problem = "There were " + to_string(total) + " cookies in a jar. " + 
                     to_string(given) + " cookies were eaten. How many cookies are left?";
            break;
        }
        case 3: {
            int students = smallNum(rng);
            int pencils = smallNum(rng);
            answer = students + pencils;
            problem = "In a classroom, there are " + to_string(students) + " students and " + 
                     to_string(pencils) + " extra pencils on the teacher's desk. " +
                     "How many students and pencils are there altogether?";
            break;
        }
        case 4: {
            int pages = smallNum(rng);
            int days = smallNum(rng);
            answer = pages * days;
            problem = "Emma reads " + to_string(pages) + " pages of her book every day. " +
                     "How many pages will she read in " + to_string(days) + " days?";
            break;
        }
        case 5: {
            int toys = mediumNum(rng);
            int boxes = smallNum(rng);
            answer = toys / boxes;
            problem = "A toy store has " + to_string(toys) + " toys to pack into " + 
                     to_string(boxes) + " boxes equally. How many toys will be in each box?";
            // Make sure division is even
            toys = answer * boxes;
            problem = "A toy store has " + to_string(toys) + " toys to pack into " + 
                     to_string(boxes) + " boxes equally. How many toys will be in each box?";
            break;
        }
        case 6: {
            int saved = mediumNum(rng);
            int earned = smallNum(rng);
            answer = saved + earned;
            problem = "Jake had saved $" + to_string(saved) + ". His grandmother gave him $" + 
                     to_string(earned) + " more. How much money does Jake have now?";
            break;
        }
    }
}

// Algebra Round for Middle School Level
void MathGame::playAlgebraRound() {
    const int questionsPerRound = 5;
    int roundScore = 0;
    
    cout << "\n### Algebra Challenge! ###" << endl;
    cout << "### Solve for x in each equation ###" << endl;
    cout << "=================================" << endl;
    
    for (int i = 1; i <= questionsPerRound; i++) {
        string equation;
        int correctAnswer;
        generateAlgebraProblem(equation, correctAnswer);
        
        cout << "\nQuestion " << i << ": " << equation << endl;
        cout << "x = ";
        
        int userAnswer;
        cin >> userAnswer;
        
        totalQuestions++;
        
        if (userAnswer == correctAnswer) {
            cout << "### Correct! ";
            correctAnswers++;
            int points = 20; // Good points for algebra
            roundScore += points;
            score += points;
            cout << "+" << points << " points!" << endl;
        } else {
            cout << "### Wrong! The correct answer is x = " << correctAnswer << endl;
        }
    }
    
    cout << "\n### Algebra Round Complete!" << endl;
    cout << "Round Score: " << roundScore << " points" << endl;
    cout << "Total Score: " << score << " points" << endl;
}

// Generate different types of algebra problems
void MathGame::generateAlgebraProblem(string& equation, int& answer) {
    uniform_int_distribution<int> problemType(1, 2);
    
    int type = problemType(rng);
    
    if (type == 1) {
        generateSimpleEquation(equation, answer);
    } else {
        generateLinearEquation(equation, answer);
    }
}

// Generate simple equations like x + 5 = 12
void MathGame::generateSimpleEquation(string& equation, int& answer) {
    uniform_int_distribution<int> operation(1, 4); // +, -, *, /
    uniform_int_distribution<int> smallNum(2, 15);
    uniform_int_distribution<int> result(10, 50);
    
    int op = operation(rng);
    int num = smallNum(rng);
    int res = result(rng);
    
    switch(op) {
        case 1: // x + num = res
            answer = res - num;
            equation = "x + " + to_string(num) + " = " + to_string(res);
            break;
        case 2: // x - num = res
            answer = res + num;
            equation = "x - " + to_string(num) + " = " + to_string(res);
            break;
        case 3: // x * num = res (make sure result is evenly divisible)
            answer = smallNum(rng);
            res = answer * num;
            equation = "x × " + to_string(num) + " = " + to_string(res);
            break;
        case 4: // x / num = res
            answer = res * num;
            equation = "x ÷ " + to_string(num) + " = " + to_string(res);
            break;
    }
}

// Generate linear equations like 2x + 3 = 11
void MathGame::generateLinearEquation(string& equation, int& answer) {
    uniform_int_distribution<int> coefficient(2, 6);
    uniform_int_distribution<int> constant(1, 10);
    uniform_int_distribution<int> xValue(1, 8);
    
    int coeff = coefficient(rng);
    int cons = constant(rng);
    answer = xValue(rng);
    
    int result = coeff * answer + cons;
    
    equation = to_string(coeff) + "x + " + to_string(cons) + " = " + to_string(result);
}