#include "wordle_game.h"
#include <algorithm>

WordleGame::WordleGame() : rng(time(nullptr)), attempts(0), maxAttempts(6) {
    initializeWordList();
    secretWord = selectRandomWord();
}

void WordleGame::initializeWordList() {
    // Common 5-letter words for Wordle
    wordList = {
        "APPLE", "BEACH", "CHAIR", "DANCE", "EARTH", "FLAME", "GLASS", "HEART",
        "IMAGE", "JAZZY", "KNIFE", "LIGHT", "MAGIC", "NIGHT", "OCEAN", "PIANO",
        "QUART", "RIVER", "STORM", "TIGER", "UNITY", "VALUE", "WATER", "YOUTH",
        "ZEBRA", "BRAVE", "CLOUD", "DREAM", "EAGLE", "FROST", "GREEN", "HAPPY",
        "IVORY", "JUMBO", "KNEEL", "LEMON", "MUSIC", "NOVEL", "OLIVE", "PEACE",
        "QUICK", "ROBOT", "SMILE", "TULIP", "URBAN", "VIVID", "WHEAT", "XENON",
        "YACHT", "ZONAL", "BREAD", "CRANE", "DRAWN", "ELBOW", "FOCUS", "GRACE",
        "HONEY", "ISSUE", "JUDGE", "KNEAD", "LEARN", "MERRY", "NOISE", "OUNCE",
        "PILOT", "QUERY", "RADIO", "SCOUT", "TRACK", "USAGE", "VOCAL", "WALTZ",
        "YIELD", "ZONED", "BLAZE", "CRISP", "DROVE", "ELITE", "FLAIR", "GROVE",
        "HURRY", "INBOX", "JUMPS", "KNEES", "LEASH", "MIXED", "NUDGE", "OPENS",
        "PLANE", "QUILT", "RAZOR", "SCALE", "TRAIN", "UPSET", "VOWEL", "WAVES",
        "YELLS", "ZONES", "BLANK", "CROWN", "DWELL", "EMPTY", "FLOAT", "GRIND",
        "HUMAN", "INPUT", "JOKES", "KINGS", "LEGAL", "MORAL", "NURSE", "OPTIC",
        "PLANT", "QUAKE", "REACH", "SCENE", "TRASH", "ULTRA", "VISTA", "WHEEL",
        "YANKS", "ZEROS", "BLINK", "CURVE", "DWARF", "ENJOY", "FLOOD", "GRIPS",
        "HUNCH", "INNER", "JUMBO", "KITTY", "LEVEL", "MOTOR", "NINJA", "ORBIT",
        "PLATE", "QUART", "REACT", "SCORE", "TREAT", "UNCLE", "VITAL", "WHILE",
        "YARDS", "ZILCH", "BLOCK", "CYCLE", "DWELL", "ENTRY", "FLOOR", "GROSS",
        "HURTS", "INSET", "JUMPS", "KNACK", "LIEGE", "MOUSE", "NIGHT", "ORDER",
        "PLUCK", "QUASH", "READY", "SCOPE", "TREND", "UNDER", "VOCAL", "WHIPS",
        "YEARS", "ZONAL", "BLOOM", "CYNIC", "EARLY", "ENVOY", "FLORA", "GROUP",
        "HUSKY", "INTRO", "JUMBO", "KNIFE", "LIGHT", "MOUNT", "NIGHT", "OTHER",
        "PLUSH", "QUAIL", "REALM", "SCORN", "TRIAL", "UNFIT", "VOICE", "WHIRL",
        "YEAST", "ZONED"
    };
}

string WordleGame::selectRandomWord() {
    uniform_int_distribution<int> dist(0, wordList.size() - 1);
    return wordList[dist(rng)];
}

string WordleGame::toUpperCase(const string& str) {
    string upper = str;
    transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
    return upper;
}

bool WordleGame::isValidGuess(const string& guess) {
    if (guess.length() != 5) {
        return false;
    }
    for (char c : guess) {
        if (!isalpha(c)) {
            return false;
        }
    }
    // Check if word is in the word list
    string upperGuess = toUpperCase(guess);
    for (const string& word : wordList) {
        if (word == upperGuess) {
            return true;
        }
    }
    return false;
}

vector<int> WordleGame::checkGuess(const string& guess) {
    // 0 = not in word (gray), 1 = wrong position (yellow), 2 = correct position (green)
    vector<int> feedback(5, 0);
    string upperGuess = toUpperCase(guess);
    string secret = secretWord;
    vector<bool> used(5, false);
    
    // First pass: mark correct positions (green)
    for (int i = 0; i < 5; i++) {
        if (upperGuess[i] == secret[i]) {
            feedback[i] = 2;
            used[i] = true;
        }
    }
    
    // Second pass: mark correct letters in wrong position (yellow)
    for (int i = 0; i < 5; i++) {
        if (feedback[i] == 2) continue; // Already marked as correct
        
        for (int j = 0; j < 5; j++) {
            if (!used[j] && upperGuess[i] == secret[j]) {
                feedback[i] = 1;
                used[j] = true;
                break;
            }
        }
    }
    
    return feedback;
}

void WordleGame::displayBoard(const vector<string>& guesses, const vector<vector<int>>& feedback) {
    cout << "\n";
    cout << "=========================================" << endl;
    cout << "           WORDLE GAME BOARD" << endl;
    cout << "=========================================" << endl;
    cout << "\n";
    
    for (size_t i = 0; i < guesses.size(); i++) {
        cout << "  ";
        for (int j = 0; j < 5; j++) {
            int status = feedback[i][j];
            if (status == 2) {
                // Green - correct position
                cout << "\033[42m\033[30m " << guesses[i][j] << " \033[0m";
            } else if (status == 1) {
                // Yellow - wrong position
                cout << "\033[43m\033[30m " << guesses[i][j] << " \033[0m";
            } else {
                // Gray - not in word
                cout << "\033[47m\033[30m " << guesses[i][j] << " \033[0m";
            }
            cout << " ";
        }
        // Show status symbols for clarity
        cout << "  ";
        for (int j = 0; j < 5; j++) {
            int status = feedback[i][j];
            if (status == 2) {
                cout << "✓";  // Correct position
            } else if (status == 1) {
                cout << "~";  // Wrong position
            } else {
                cout << "X";  // Not in word
            }
        }
        cout << "\n";
    }
    
    // Show empty rows for remaining attempts
    for (int i = guesses.size(); i < maxAttempts; i++) {
        cout << "  ";
        for (int j = 0; j < 5; j++) {
            cout << "[ ] ";
        }
        cout << "\n";
    }
    
    cout << "\n";
    cout << "Legend: ";
    cout << "\033[42m\033[30m Green/✓ \033[0m = Correct position, ";
    cout << "\033[43m\033[30m Yellow/~ \033[0m = Wrong position, ";
    cout << "\033[47m\033[30m Gray/X \033[0m = Not in word";
    cout << "\n";
    cout << "=========================================" << endl;
    cout << "\n";
}

void WordleGame::displayWelcome() {
    cout << "\n### WELCOME TO WORDLE! ###" << endl;
    cout << "===========================" << endl;
    cout << "Guess the 5-letter word in " << maxAttempts << " attempts!" << endl;
    cout << "After each guess, you'll see:" << endl;
    cout << "  - Green: Letter is correct and in the right position" << endl;
    cout << "  - Yellow: Letter is in the word but wrong position" << endl;
    cout << "  - Gray: Letter is not in the word" << endl;
    cout << "===========================" << endl << endl;
}

void WordleGame::run() {
    displayWelcome();
    
    vector<string> guesses;
    vector<vector<int>> feedback;
    string guess;
    
    while (attempts < maxAttempts) {
        cout << "Attempt " << (attempts + 1) << " of " << maxAttempts << endl;
        cout << "Enter your 5-letter word guess: ";
        cin >> guess;
        
        // Convert to uppercase for consistency
        guess = toUpperCase(guess);
        
        if (!isValidGuess(guess)) {
            cout << "### Invalid guess! Please enter a valid 5-letter word." << endl;
            cout << "The word must be in the dictionary and contain only letters." << endl << endl;
            continue;
        }
        
        attempts++;
        guesses.push_back(guess);
        
        vector<int> result = checkGuess(guess);
        feedback.push_back(result);
        
        displayBoard(guesses, feedback);
        
        // Check if player won
        bool allCorrect = true;
        for (int status : result) {
            if (status != 2) {
                allCorrect = false;
                break;
            }
        }
        
        if (allCorrect) {
            cout << "### CONGRATULATIONS! You guessed the word!" << endl;
            cout << "The word was: " << secretWord << endl;
            if (attempts == 1) {
                cout << "### INCREDIBLE! Perfect guess!" << endl;
            } else if (attempts <= 3) {
                cout << "### EXCELLENT! Great job!" << endl;
            } else if (attempts <= 5) {
                cout << "### WELL DONE! Nice work!" << endl;
            } else {
                cout << "### GOOD JOB! You got it!" << endl;
            }
            return;
        }
        
        if (attempts < maxAttempts) {
            cout << "Remaining attempts: " << (maxAttempts - attempts) << endl << endl;
        }
    }
    
    // Player ran out of attempts
    cout << "### GAME OVER! You ran out of attempts." << endl;
    cout << "The word was: " << secretWord << endl;
    cout << "Better luck next time!" << endl;
}

