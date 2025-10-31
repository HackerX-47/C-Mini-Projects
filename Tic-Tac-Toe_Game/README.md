# ❌⭕ Tic-Tac-Toe Game (C Language)

A console-based, menu-driven C program that allows two players to play a classic game of Tic-Tac-Toe.

---

## 🚀 Getting Started

### Prerequisites

This program is written in standard C and requires a C compiler (like GCC) to be compiled and executed.

### Compilation and Execution

1.  **Save the code:** Save the provided C code as a file named `tictactoe.c`.
2.  **Compile:** Open your terminal or command prompt and compile the program using a C compiler:
    ```bash
    gcc tictactoe.c -o tictactoe
    ```
3.  **Run:** Execute the compiled program:
    ```bash
    ./tictactoe
    ```

---

## 🕹️ How to Play

The game is controlled via a simple menu and positional inputs.

### Game Setup

* **Player 1** uses the symbol **'X'**.
* **Player 2** uses the symbol **'O'**.
* The board positions are numbered **1 through 9** as shown below:
```bash
 1 | 2 | 3 
---+---+---
 4 | 5 | 6
---+---+---
 7 | 8 | 9
```
### Program Menu

When prompted with **"Tell me choice?"**:
* Enter **`1`** to **start a new game**.
* Enter **`0`** to **exit the program**.

### Making a Move

During the game, the program will prompt the current player for their move (e.g., "Player 1 chance?").
* Enter a number from **1 to 9** corresponding to the **empty cell** where you wish to place your symbol.
* Invalid inputs (numbers outside of 1-9 or positions already taken) will result in a prompt to re-enter a valid position.

### Winning Condition

The first player to get **three** of their symbols in a **horizontal, vertical, or diagonal** line wins the game. If all cells are filled and no one wins, the game is a **draw**.

---

## 🛠️ Program Structure

The program is modularized into several C functions, each responsible for a specific part of the game logic.

| Function Prototype | Description |
| :--- | :--- |
| `void displayBoard(char board[9])` | Prints the current state of the Tic-Tac-Toe board to the console. |
| `int input(int counter, char board[9], int chosenValues[9])` | Handles user input for the current player's move, validates the position, updates the board, and returns the chosen position. |
| `int win(int counter, char board[9], int chosenValues[9])` | Checks the board state after a move to determine if a player has won or if the game is a draw. Returns `1` if a win/draw occurs, and `0` otherwise. |
| `int subset(int array1[3], int array2[5])` | Helper function to check if the 3-element winning condition array (`array1`) is a subset of a player's moves array (`array2`). |
| `void instructions()` | Displays the game rules and program usage instructions. |
| `int main(void)` | The main function that controls the program's flow, initializes the game, and handles the menu loop. |

---

## 👤 Author

This project was created by **Omkar**<br>
**📧 Email:** [omkar121207@gmail.com](mailto:omkar121207@gmail.com)  
**🐙 GitHub:** [HackerX-47](https://github.com/HackerX-47) <br>
**🔗 LinkedIn:** [Omkar Singh](https://www.linkedin.com/in/omkar-singh-ba2653381/)  
**💻 LeetCode:** [HackerX_47](https://leetcode.com/u/HackerX_47/)
* **Repository Location:** `C-Mini-Projects/Tic-Tac-Toe_Game`

---