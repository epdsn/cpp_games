# C++ Game Collection

A comprehensive console-based game collection written in C++ featuring three exciting games! This project demonstrates various C++ concepts including object-oriented programming, random number generation, and interactive console applications.

## 🎮 Game Collection

### 1. 🎯 Number Guessing Game
A classic guessing game where you try to guess a random number between 1-100! The computer provides hints after each guess:
- **"Too high!"** - Your guess is greater than the secret number
- **"Too low!"** - Your guess is less than the secret number
- **"Congratulations!"** - You guessed correctly!

**Features:**
- Attempt tracking
- Performance ranking based on number of tries
- Personalized feedback

### 2. 🧮 Math Master Game
Test your math skills with this interactive quiz game featuring multiple difficulty levels!

**Features:**
- **3 Difficulty Levels:**
  - Easy: Addition & Subtraction (1-20)
  - Medium: All operations (1-50) 
  - Hard: All operations (1-100)
- **Scoring System:** Earn points for correct answers
- **Statistics Tracking:** View accuracy percentage and ranking
- **Achievement System:** Math Master, Expert, Scholar rankings

### 3. 🏰 Dungeon Crawler Game
Create your character and prepare for adventure in this RPG-style character creation system!

**Features:**
- **4 Character Classes:**
  - 🗡️ **Warrior**: High strength, masters of combat
  - 🔮 **Mage**: High magic, wielders of powerful spells
  - ⚖️ **Paladin**: Balanced holy warriors
  - 🏹 **Ranger**: Versatile and swift adventurers

- **Class-Specific Weapons:**
  - Warriors: Iron Sword, War Hammer, Sword & Shield
  - Mages: Crystal Staff, Spell Tome, Lightning Wand
  - Paladins: Holy Blade, Divine Mace, Sacred Shield
  - Rangers: Elven Bow, Twin Blades, Crossbow

- **Stat Allocation:** Distribute 10 bonus points between Strength and Magic
- **Character Sheet:** Complete overview of your character's abilities
- **RPG Elements:** Health, level, and gold tracking

## 📋 Prerequisites

- **Windows** (this project is set up for Windows)
- **Visual Studio 2019 or later** with "Desktop development with C++" workload installed
  - OR **MSVC compiler** (cl.exe) available in your PATH
  - OR **MinGW-w64** (g++) if you prefer using g++

## 🚀 How to Compile and Run

### Method 1: Using g++ (Recommended)

If you have g++ installed (like MinGW-w64):

1. Open PowerShell or Command Prompt
2. Navigate to the project directory:
   ```bash
   cd "C:\Users\ep1\source\repos\cpp_games\cpp_games\CPP_console_app"
   ```
3. Compile the program:
   ```bash
   g++ -o games.exe CPP_console_app.cpp
   ```
4. Run the game collection:
   ```bash
   .\games.exe
   ```

### Method 2: Using Visual Studio IDE

1. Open `CPP_console_app.sln` in Visual Studio (if project files work)
2. Press **F5** to build and run
   - Or go to **Build → Build Solution** (Ctrl+Shift+B), then run the executable

### Method 3: Using Command Line with MSVC

1. Open **"x64 Native Tools Command Prompt for VS 2019"** (or your VS version)
2. Navigate to the project directory:
   ```bash
   cd C:\Users\ep1\source\repos\cpp_games\cpp_games\CPP_console_app
   ```
3. Compile the program:
   ```bash
   cl CPP_console_app.cpp
   ```
4. Run the executable:
   ```bash
   CPP_console_app.exe
   ```

## 🎮 How to Play

1. **Start the Game Collection:**
   - Enter your name when prompted
   - Choose from the main menu:

2. **Game Menu:**
   ```
   1. Number Guessing Game
   2. Math Master Game  
   3. Dungeon Crawler Game
   4. Quit
   ```

3. **Play Your Chosen Game:**
   - Each game has its own rules and objectives
   - Return to main menu to try different games
   - Your name is used throughout for personalization

## 📁 Project Structure

```
cpp_games/
├── CPP_console_app/
│   ├── CPP_console_app.cpp    # Main source code (all games)
│   └── CPP_console_app.vcxproj # Visual Studio project file
├── CPP_console_app.sln        # Visual Studio solution file
├── .gitignore                 # Git ignore file
└── README.md                  # This file
```

## 🎓 Learning Concepts Covered

This game collection demonstrates:

### **Object-Oriented Programming**
- **Classes and Objects**: Each game is its own class
- **Encapsulation**: Private member variables and public methods
- **Constructors**: Proper initialization of game objects
- **Method Organization**: Logical separation of functionality

### **Modern C++ Features**
- **Random Number Generation**: `mt19937` Mersenne Twister generator
- **STL Containers**: `vector`, `string`, `pair`
- **Smart Memory Management**: No manual memory allocation needed

### **Game Programming Concepts**
- **State Management**: Character stats, game scores, player progress
- **Menu Systems**: Interactive console menus with validation
- **User Experience**: Personalized gameplay with player names

### **Core Programming Concepts**
1. **Data Types & Variables**: `int`, `string`, `char`, `double`
2. **Control Flow**: 
   - `do-while` and `for` loops
   - `switch` statements and complex conditionals
   - Function calls and returns

3. **Input/Output**:
   - `cout`/`cin` for console interaction
   - Formatted output with `iomanip`
   - Input validation

4. **Functions & Methods**:
   - Parameter passing
   - Return values
   - Method overloading concepts

## 💻 Code Architecture

### **Game Structure**
```cpp
class GameName {
private:
    // Game state variables
    mt19937 rng;              // Random number generator
    string playerName;        // Player personalization
    // Game-specific variables...
    
public:
    GameName(const string& name);  // Constructor
    void run();               // Main game loop
    // Game-specific methods...
};
```

### **Main Application Flow**
1. **Welcome & Name Input**: Personalize the experience
2. **Main Menu Loop**: Choose between games
3. **Game Execution**: Run selected game
4. **Return to Menu**: Seamless game switching

## � Future Enhancements

### **Number Guessing Game**
- Multiple difficulty levels (different ranges)
- High score tracking
- Hint system

### **Math Master Game**
- Timed challenges
- Multiplication tables practice
- Fraction and decimal problems
- Leaderboard system

### **Dungeon Crawler Game**
- **Combat System**: Battle monsters with turn-based combat
- **Exploration**: Navigate through procedurally generated dungeons  
- **Inventory System**: Collect and manage items
- **Experience & Leveling**: Character progression
- **Treasure & Loot**: Find gold and equipment upgrades
- **Save/Load System**: Persistent character data

### **General Enhancements**
- **Cross-platform Support**: Linux and macOS compatibility
- **Graphics Interface**: Upgrade from console to GUI
- **Multiplayer Features**: Network gameplay options
- **Configuration System**: Save player preferences

## 🐛 Troubleshooting

### **Compilation Issues**

#### "g++ is not recognized"
- Install MinGW-w64 or add g++ to your PATH:
  ```bash
  set PATH=%PATH%;C:\msys64\mingw64\bin
  ```
- Or use the full path: `C:\msys64\mingw64\bin\g++.exe`

#### "cl is not recognized" 
- Use the **Developer Command Prompt** for Visual Studio
- Or add MSVC to your PATH

#### Compilation Errors
- Ensure you have C++11 support: `g++ -std=c++11 -o games.exe CPP_console_app.cpp`
- Check all `#include` statements are correct
- Make sure you're in the correct directory

### **Runtime Issues**

#### Program Crashes on Startup
- Check that you're entering valid input when prompted
- Try compiling with debug info: `g++ -g -o games.exe CPP_console_app.cpp`

#### Games Don't Work Correctly
- Ensure you're entering valid numbers when prompted
- Check that random number generator is working (should be automatic)

#### Visual Studio Project Issues
- The `.vcxproj` files may have compatibility issues
- Use g++ compilation method instead
- Or create a new Visual Studio project and copy the `.cpp` file

## 📄 License

This is a learning project - feel free to use and modify as you wish!

## 🤝 Contributing

This is a personal learning project, but suggestions and improvements are welcome!
- Fork the repository
- Make your improvements  
- Submit a pull request
- Share your ideas for new games or features!

---

**Happy Gaming and Coding!** 🎉🎮🎯

