# 🎯 Guess The Number Game

A simple **C language console game** where the player tries to guess a randomly generated number within a given range and limited number of trials.

---

## 🧩 Introduction

Welcome to **Guess The Number Game** — a beginner-friendly C program that tests your logical thinking and number intuition!  
The program generates a random number within a user-specified range, and the player must guess it correctly within **3 attempts**.

This project demonstrates the use of:
- Loops (`while`, `for`)
- Conditional statements (`if`, `else if`, `else`)
- Random number generation (`rand()` and `srand()`)
- User input handling with `scanf()`
- Modular programming using a custom function `instructions()`

---

## ✨ Features

- 🎲 Random number generation for each round  
- 🧠 Three trials per round  
- ⚠️ Validation for invalid and out-of-range inputs  
- 🔁 Option to replay until the user enters `0`  
- 🕹️ Simple and user-friendly interface  
- 🧾 Detailed instructions printed before the game starts  

---

## 💡 Concepts Used

| Concept | Description |
|----------|--------------|
| `rand()` and `srand()` | Used to generate pseudo-random numbers. |
| `time(NULL)` | Seeds the random number generator with current time. |
| `if-else` statements | For decision making during the game. |
| `for` loop | Provides up to three guessing attempts. |
| `while` loop | Allows the game to repeat until user chooses to quit. |
| Function | `instructions()` displays how to play the game. |

---

## ⚙️ How to Run

1. **Clone or download** this repository to your system.
   ```bash
   git clone https://github.com/<your-username>/Guess-The-Number-Game.git
   ```
2. **Navigate to the project directory** 
  ```bash
  cd Guess-The-Number-Game
  ```
3. **Compile** the code using gcc.
  ```bash
  gcc guess_the_number.c -o guess
  ```
4. **Run** the executable.
  ```bash
  ./guess
  ```

## Sample Outputs

 ## 🟢 Case 1: User enters 0 (exit)
```bash
---- Guess The Number ----
Instructions:
1. Enter the maximum number (option).
2. Try to guess the number between 1 and that number.
3. Enter 0 to quit the game.
4. 1 is not a valid input in this game.

Tell me the option=
? 0
Program terminating ...
```

## 🟠 Case 2: User enters invalid input (like 1 or negative number)
```bash
Tell me the option=
? 1
You made a wrong input.
Try again.
Instructions:
1. Enter the maximum number (option).
2. Try to guess the number between 1 and that number.
3. Enter 0 to quit the game.
4. 1 is not a valid input in this game.
```

## 🧠 Case 3: User plays the game (option = 10)
```bash
Tell me the option=
? 10
Trial 1:-
Guess the number
? 5
The guess was low.
Try again
Trial 2:-
Guess the number
? 8
The guess was high.
Try again
Trial 3:-
Guess the number
? 7
You made it in the trial 3.
You guessed the number right.

Tell me the option=
? 0
Program terminating ...
```

## 🚫 Case 4: User guesses outside range
```bash
Tell me the option=
? 5
Trial 1:-
Guess the number
? 10
Input is outside the range.
Try again
Trial 2:-
Guess the number
? 3
The guess was low.
Try again
Trial 3:-
Guess the number
? 4
You lose.
Try again.
```

### 📂 File Structure
```bash
Guess-The-Number-Game/
│
├── guess_the_number.c   # Main source code
├── README.md            # Project documentation (this file)
```

### 👨‍💻 Author Info

This project was created by  **Omkar**
**📧 Email:** [omkar121207@gmail.com](mailto:omkar121207@gmail.com)  
**🐙 GitHub:** [HackerX-47](https://github.com/HackerX-47)  
**🔗 LinkedIn:** [Omkar Singh](https://www.linkedin.com/in/omkar-singh-ba2653381/)  
**💻 LeetCode:** [HackerX_47](https://leetcode.com/u/HackerX_47/)