# 🧠 Dynamic Quiz Game in C

A **fully dynamic quiz game** written in C that allows users to play, add, and randomize questions — all managed through a single session.  
Built with focus on **file handling, dynamic memory allocation, user interaction**, and **input validation**.

---

## 📜 Features

✅ **Preloaded Questions** – The game starts with 10 built-in general knowledge questions.  
✅ **Add Your Own Questions** – Users can dynamically add new questions during runtime.  
✅ **Randomized Gameplay** – Questions appear in a random order each time the quiz starts.  
✅ **File Handling** – Questions are stored and accessed through a text file (`Questions.txt`).  
✅ **Memory Management** – Uses dynamic allocation for options and properly frees memory.  
✅ **Input Validation** – Ensures only valid menu choices and answer inputs are accepted.  

---

## 🧩 How It Works

1. **The program starts and displays a main menu:**
```bash
Enter one of the following choices:
0 - Exit the program
1 - Play the quiz game
2 - Add a new question
```
2. **Play Game (1):**
- Loads 10 fixed questions + any user-added ones.
- Randomizes question order each time.
- User answers by typing `A`, `B`, `C`, or `D`.
- Final score is displayed at the end.

3. **Add Question (2):**
- Prompts the user to enter:
  - Question text
  - Four options (one per line)
  - Correct answer (`A/B/C/D`)
- Question is stored temporarily (resets when program restarts).

4. **Exit (0):**
- Ends the program cleanly.

---

## 🧠 Concepts Used

- **Structures** – For question storage  
- **Dynamic Memory Allocation (`malloc`, `free`)**  
- **File Handling (`fopen`, `fprintf`, `fgets`, `rewind`)**  
- **Random Number Generation (`rand`, `srand`, `time`)**  
- **Enumerations (enum Choice)**  
- **Input Validation with `toupper()` and loops**  

---

## 📂 File Information

**File:** `Questions.txt`  
- Stores all quiz data (questions, options, answers).  
- Automatically created and managed by the program.  
- Uses `w+` mode (fresh start each time).  

---

## ⚙️ Future Improvements

- Display correct answer after wrong response  
- Add difficulty levels or category selection  
- Save player scores in a leaderboard  

---

## 🧑‍💻 Author

This project was created by **Omkar**.

Omkar<br>
**📧 Email:** [omkar121207@gmail.com](mailto:omkar121207@gmail.com)  
**🐙 GitHub:** [HackerX-47](https://github.com/HackerX-47) 
**🔗 LinkedIn:** [Omkar Singh](https://www.linkedin.com/in/omkar-singh-ba2653381/)  
**💻 LeetCode:** [HackerX_47](https://leetcode.com/u/HackerX_47/)
* **Repository Location:** `C-Mini-Projects/Dynamic_Quiz_Game`
---

