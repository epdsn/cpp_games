# Number Guessing Game

A simple console-based number guessing game written in C++ for learning purposes. This project demonstrates fundamental C++ concepts including loops, conditionals, input/output, and random number generation.

## 🎮 Game Description

The computer generates a random number between 0 and 10, and you try to guess it! After each guess, you'll receive feedback:
- **"Too high!"** - Your guess is greater than the secret number
- **"Too low!"** - Your guess is less than the secret number
- **"Congratulations!"** - You guessed correctly!

The game tracks how many attempts it takes you to find the correct number.

## 📋 Prerequisites

- **Windows** (this project is set up for Windows)
- **Visual Studio 2019 or later** with "Desktop development with C++" workload installed
  - OR **MSVC compiler** (cl.exe) available in your PATH
  - OR **MinGW-w64** (g++) if you prefer using g++

## 🚀 How to Compile and Run

### Method 1: Using Visual Studio IDE (Easiest)

1. Open `CPP_console_app.sln` in Visual Studio
2. Press **F5** to build and run
   - Or go to **Build → Build Solution** (Ctrl+Shift+B), then run the executable

### Method 2: Using Command Line with MSVC

1. Open **"x64 Native Tools Command Prompt for VS 2019"** (or your VS version)
   - Search for it in the Start Menu
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

### Method 3: Using g++ (MinGW-w64)

If you have g++ installed and in your PATH:

1. Open PowerShell or Command Prompt
2. Navigate to the project directory:
   ```bash
   cd C:\Users\ep1\source\repos\cpp_games\cpp_games\CPP_console_app
   ```
3. Compile the program:
   ```bash
   g++ -o guessing_game CPP_console_app.cpp
   ```
4. Run the executable:
   ```bash
   .\guessing_game.exe
   ```

## 📁 Project Structure

```
cpp_games/
├── CPP_console_app/
│   ├── CPP_console_app.cpp    # Main source code
│   └── CPP_console_app.vcxproj # Visual Studio project file
├── CPP_console_app.sln        # Visual Studio solution file
└── README.md                  # This file
```

## 🎓 Learning Concepts Covered

This project demonstrates:

1. **Basic C++ Syntax**
   - Includes (`#include`)
   - Namespace usage (`using namespace std`)
   - Main function structure

2. **Data Types**
   - `int` for integers
   - Variable declaration and initialization

3. **Input/Output**
   - `cout` for output
   - `cin` for input
   - Stream operators (`<<` and `>>`)

4. **Control Flow**
   - `do-while` loops
   - `if/else if/else` conditionals
   - Comparison operators (`==`, `>`, `<`, `!=`)

5. **Random Number Generation**
   - `srand()` to seed the random number generator
   - `rand()` to generate random numbers
   - Modulo operator (`%`) to limit range

6. **Variable Manipulation**
   - Increment operator (`++`)
   - Variable assignment

## 💻 Code Overview

The game uses a simple `do-while` loop that:
1. Prompts the user for a guess
2. Reads the input
3. Increments the attempt counter
4. Compares the guess to the secret number
5. Provides feedback
6. Continues until the guess is correct

All code includes detailed comments explaining each concept for learning purposes.

## 🐛 Troubleshooting

### "cl is not recognized"
- Make sure you're using the **Developer Command Prompt** for Visual Studio
- Or add MSVC to your PATH (see setup instructions)

### "g++ is not recognized"
- Install MinGW-w64 or MSYS2
- Add the `bin` folder to your system PATH
- Restart your terminal after adding to PATH

### Compilation Errors
- Ensure you have the C++ workload installed in Visual Studio
- Check that you're using a compatible compiler version
- Make sure all `#include` statements are correct

### Program Runs but Doesn't Work Correctly
- Check that you're entering valid integers (0-10)
- Ensure the random number generator is seeded (should be automatic)

## 📝 Future Enhancements

Ideas to extend this project:
- Add difficulty levels (different number ranges)
- Limit the number of attempts
- Add a "play again" feature
- Keep track of best score
- Add input validation for non-numeric input
- Use more modern C++ features (C++11 random library instead of `rand()`)

## 📄 License

This is a learning project - feel free to use and modify as you wish!

## 🤝 Contributing

This is a personal learning project, but suggestions and improvements are welcome!

---

**Happy Coding!** 🎉

