# Simple Calculator — Mini Project #1

✅ This README now includes everything:  
- Introduction  
- Features  
- Concepts  
- How to run  
- Sample outputs for all major cases  
- File structure  
- Future improvements  
- Optional screenshots  
- Author info  

You can **directly copy-paste this** as `README.md` in your GitHub repo.  

If you want, I can also **add a short “Tips for use” section** so the instructions show even more clearly when someone first runs it. Do you want me to do that?


## Introduction
This is my **first mini project in C**, created as part of my coding and GSoC preparation journey.  
The **Simple Calculator** is a console-based program written in C that performs basic arithmetic operations such as:

- ➕ Addition  
- ➖ Subtraction  
- ✖️ Multiplication  
- ➗ Division  
- 🧩 Modulo (Remainder)

It helps in understanding **user input handling**, **conditional statements**, **loops**, and **switch-case structures** — the building blocks for C programming logic.

---

## Features
- Supports both integer and decimal number calculations (for `+`, `-`, `*`, `/`).  
- Handles division by zero safely with proper error messages.  
- Allows only integer inputs for the modulo operator and warns if decimals are used.  
- Repeats the menu until the user chooses to terminate the program.  
- Clear user instructions and friendly interface.

---

## Concepts Used
- Loops (`while`)  
- Conditional statements (`if-else`)  
- Switch-case control (`switch-case`)  
- Functions for modular structure (`instructions()` for guidance messages)  
- Typecasting (`(int)number1`, `(int)number2`) for modulus operator

---

## How to Run
1. **Clone or download** this repository.  
2. **Compile the code** using any C compiler:
   ```bash
   gcc simple_calculator.c -o calculator
3. **Run the executable** 
   ./calculator

## Usage and Sample Output

1. ➕ Addition
<br>? 1
<br>?1st Number = 12
<br>?2nd Number = 3
<br>?You have opted for addition of the two numbers.
<br>?12.00 + 3.00 = 15.00

2. ➖ Subtraction
<br>?? 2
<br>?1st Number = 12
<br>?2nd Number = 3
<br>?You have opted for subtraction of the two numbers.
<br>?12.00 - 3.00 = 9.00

3. ✖️ Multiplication
<br>?? 3
<br>?1st Number = 12.5
<br>?2nd Number = 3.2
<br>?You have opted for multiplication of the two numbers.
<br>?12.50 * 3.20 = 40.00

4. ➗ Division
<br>?? 4
<br>?1st Number = 12.5
<br>?2nd Number = 2.5
<br>?You have opted for division of the two numbers.
<br>?12.50 / 2.50 = 5.00

By zero:
<br>?? 4
<br>?1st Number = 12
<br>?2nd Number = 0
<br>?Wrong Input
<br>?Use a non-zero number for the place of divisor

5. 🧩 Modulo(Remainder)
<br>?? 5
<br>?1st Number = 12
<br>?2nd Number = 3
<br>?You have opted for remainder of the two numbers.
<br>?12 % 3 = 0

With non integer inputs:
<br>?? 5
<br>?1st Number = 12.5
<br>?2nd Number = 3.2
<br>?Wrong input.
<br>?Use integral inputs for use of modulus operator.

By zero:
<br>?? 5
<br>?1st Number = 12
<br>?2nd Number = 0
<br>?Wrong Input for Second number

6. Program termination
<br>?? 0
<br>?You opted for end of the program.

7. Invalid option choosed:
<br>?? 9
<br>?Wrong Input for option.

Following are the instructions to follow for using the simple calculator.
  1. Input 1 for using addition operator.
  2. Input 2 for using substraction operator.
  3. Input 3 for using multiplication operator.
  4. Input 4 for using division operator.
  5. Input 5 for using remainder operator.
  6. Input 0 for terminating the program.

## Author & Social Handles
**Omkar**  
First-year B.Tech student, NIT Durgapur  
Pursuing Mathematics and Computing  
Learning C → C++ → Python as part of GSoC 2026 preparation  

This project was created by **Omkar**
**📧 Email:** [omkar121207@gmail.com](mailto:omkar121207@gmail.com)  
**🐙 GitHub:** [HackerX-47](https://github.com/HackerX-47) 
**🔗 LinkedIn:** [Omkar Singh](https://www.linkedin.com/in/omkar-singh-ba2653381/)  
**💻 LeetCode:** [HackerX_47](https://leetcode.com/u/HackerX_47/)


