```text
██╗   ██╗██╗███╗   ██╗████████╗ █████╗  ██████╗  ██████╗ ███████╗
██║   ██║██║████╗  ██║╚══██╔══╝██╔══██╗██╔════╝ ██╔═══██╗██╔════╝
██║   ██║██║██╔██╗ ██║   ██║   ███████║██║  ███╗██║   ██║███████╗
╚██╗ ██╔╝██║██║╚██╗██║   ██║   ██╔══██║██║   ██║██║   ██║╚════██║
 ╚████╔╝ ██║██║ ╚████║   ██║   ██║  ██║╚██████╔╝╚██████╔╝███████║
  ╚═══╝  ╚═╝╚═╝  ╚═══╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝  ╚═════╝ ╚══════╝
         V I N T A G E   B A N K   A C C O U N T   M A N A G E R
```
---

## 📘 Project Overview

**VINTAGE Bank Account Manager** is a **C-based command-line banking system** built to simulate the essential features of account management.  
It demonstrates structured programming, file handling, and modular design — ideal for showcasing strong fundamentals in C programming.

This project serves as part of **Omkar’s GSoC 2026 preparation roadmap**, focusing on writing clean, efficient, and modular C code for real-world simulations.

---

## ⚙️ Features

| Feature | Description |
|:--------|:-------------|
| 🧾 **Account Creation** | Automatically generates a unique 10-digit account number (e.g., `0000000001`) and stores details in a text file. |
| 🗑️ **Account Deletion** | Securely removes an account entry by rewriting all other records. |
| 💸 **Deposit / Withdraw** | Allows money transactions while validating balances to prevent overdrafts. |
| 🔍 **Balance Inquiry** | Retrieves and displays stored account details neatly. |
| 🧭 **Menu Navigation** | Interactive console-based interface with continuous looping until the user exits. |
| 🗂️ **Data Persistence** | All account records are stored permanently in `accounts.txt` using structured text format. |

---

## 💪 Program Strengths

✅ **Structured Code:**  
Each function handles one task (`createAccount`, `deleteAccount`, etc.), following a clean modular structure.

✅ **Safe Input Handling:**  
Uses field-width specifiers (like `%30s`, `%10s`) to prevent buffer overflow.

✅ **Data Persistence:**  
All account information is safely stored and updated using file I/O (`fprintf`, `fscanf`, `rename`, `remove`, etc.).

✅ **Error Handling:**  
Detects file opening/writing errors and prevents crashes gracefully.

✅ **Readable Output:**  
Displays all operations and results in a clear, formatted, and minimal console layout.

✅ **Extendable Design:**  
The code structure allows easy integration of future features like authentication, transaction history, or database storage.

✅ **Portable:**  
No dependencies — works on any C compiler on Windows, Linux, or macOS.

---

## 🧠 Concepts Demonstrated

- File handling (`fopen`, `fprintf`, `fscanf`, `remove`, `rename`, `rewind`, `fflush`)
- Use of `struct` for data organization  
- Enumerations for menu-driven program flow  
- Modular design and function reusability  
- Input validation and error checking  
- Clean console I/O formatting

---

## 🧩 Program Flow
```bash
+-------------------------------------------------------------+

MAIN FUNCTION
1. Opens "accounts.txt" in w+ mode
2. Displays menu options
3. Takes user input for operation
4. Executes corresponding function
5. Loops until user selects EXIT (0)

+-------------------------------------------------------------+
```


---

## 📂 File Structure
```bash
Bank-Account-Manager
│
├── vintage_bank_manager.c # Main source code file
├── accounts.txt # Stores all bank account data
├── temp.txt # Temporary file for updates/deletions
└── README.md # Project documentation (this file)
```

---

## 🧱 Function Breakdown

### `instructions()`
Displays all menu options in a neat, boxed format.

### `createAccount(FILE *fPtr, int createdAccountCounter)`
- Generates a unique 10-digit account number  
- Takes first and last name  
- Initializes balance to 0  
- Writes details to file  
- Displays confirmation and account info

### `deleteAccount(FILE *fPtr)`
- Prompts for account number  
- Copies all records except the one to delete into a temp file  
- Replaces original file with the updated one

### `deposit_OR_withdraw(FILE *fPtr, int option)`
- Handles both deposit (`option = 1`) and withdrawal (`option = 2`)  
- Prevents withdrawal if insufficient balance  
- Updates the account balance safely

### `balanceInquiry(FILE *fPtr)`
- Searches by account number  
- Displays all details if found, or an error if not

---

## 🧮 Menu Options

| Input | Action |
|:-----:|:--------|
| 0 | Exit Program |
| 1 | Create Account |
| 2 | Delete Account |
| 3 | Deposit Money |
| 4 | Withdraw Money |
| 5 | Balance Inquiry |

---

## 🚀 Compilation & Execution

### **Using GCC**
```bash
gcc Bank_Account_Manger.c -o bank
./bank
```
---

## 🧩 Example Run
``` bash
+------------------------------------+
|       Bank Account Manager         |
+------------------------------------+

+----------------------------------------+
|             MENU OPTIONS               |
+----------------------------------------+
| 0 - Exit Program                       |
| 1 - Create New Account                 |
| 2 - Delete Existing Account            |
| 3 - Deposit Money                      |
| 4 - Withdraw Money                     |
| 5 - Balance Inquiry                    |
+----------------------------------------+

Tell me the option you want to choose :- 1

--------------------------------
        Create Account
--------------------------------
First Name :-
Omkar
Last Name :-
Sarkar

Account successfully created
Account Details :-
Account Number :- 0000000001
First Name :- Omkar
Last Name :- Sarkar
Balance :- 0
```
## 🔮 Future Enhancements
- Add PIN authentication for account access
- Implement transaction logs and history tracking
- Support binary file storage for faster access
- Add interest calculation system
- Create GUI or Web version later using C++ or Python

--- 

## 🧑‍💻 Author

This project was created by **Omkar**.<br>
**📧 Email:** [omkar121207@gmail.com](https://mail.google.com/mail/?view=cm&fs=1&to=omkar121207@gmail.com)<br> 
**🐙 GitHub:** [HackerX-47](https://github.com/HackerX-47) <br>
**🔗 LinkedIn:** [Omkar Singh](https://www.linkedin.com/in/omkar-singh-ba2653381/)  
**💻 LeetCode:** [HackerX_47](https://leetcode.com/u/HackerX_47/)
* **Repository Location:** `C-Mini-Projects/Bank_Account_Manager`
---