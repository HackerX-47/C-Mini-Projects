# 🌡️ Temperature Converter Program

## 🧭 Index
1. [Introduction](#introduction)  
2. [Features](#features)  
3. [Concepts Used](#concepts-used)  
4. [How to Run](#how-to-run)  
5. [Sample Outputs](#sample-outputs)  
6. [File Structure](#file-structure)  
7. [Author Info](#author-info)

---

## 🧩 Introduction
This is a simple **C program** that converts a given temperature between **Celsius** and **Fahrenheit** as per the user’s input.  
The program allows users to continuously perform conversions until they choose to exit.  
It also provides clear on-screen instructions and handles invalid inputs gracefully.

---

## ⚙️ Features
- 🔁 Converts **Celsius → Fahrenheit** and **Fahrenheit → Celsius**  
- 🧠 Handles both uppercase and lowercase inputs (C/F/E)  
- ❌ Detects and reports invalid units  
- 🔄 Runs in a loop until user enters **E** to exit  
- 💬 User-friendly prompts and clear instructions

---

## 💡 Concepts Used
- Functions (`void instructions(void)`)  
- Conditional statements (`if`, `else if`, `else`)  
- Loops (`while`)  
- Input and output using `scanf()` and `printf()`  
- Character handling using `ctype.h` (`toupper()` function)

---

## 🚀 How to Run

### Step 1: Clone or Download
Clone this repository or download the `.c` file.

```bash
git clone https://github.com/HackerX-47/temperature-converter.git
```

### Step 2: Compile the Program
Use any C compiler. Example using GCC:
```bash
gcc temperature_converter.c -o temperature_converter
```

### Step 3: Run the Executable
```bash
./temperature_converter
```

## 🧾 Sample Outputs

### 🧮 Case 1: Celsius → Fahrenheit
```bash
---- Temperature Converter Program ----

Instructions:
1. Input unit as C if you want to convert to Fahrenheit from Celsius
2. Input unit as F if you want to convert to Celsius from Fahrenheit
3. Input E for terminating the program

Unit=C
Tell me the numerical value of temperature = 0
Converted Temperature
32.00 F
Unit=E
Program terminating ...
```

### 🌡️ Case 2: Fahrenheit → Celsius
```bash
---- Temperature Converter Program ----
Unit=F
Tell me the numerical value of temperature = 98.6
Converted Temperature
37.00 C
Unit=E
Program terminating ...
```

### ⚠️ Case 3: Invalid Input
```bash
---- Temperature Converter Program ----
Unit=X
Wrong unit input.
Try again

Instructions:
1. Input unit as C if you want to convert to Fahrenheit from Celsius
2. Input unit as F if you want to convert to Celsius from Fahrenheit
3. Input E for terminating the program

Unit=E
Program terminating ...
```

## 📂 File Structure
```bash
temperature-converter/
│
├── temperature_converter.c   # Main program file
└── README.md                 # Documentation file (this file)
```

 ### 👨‍💻 Author Info

This project was created by **Omkar**
**📧 Email:** [omkar121207@gmail.com](mailto:omkar121207@gmail.com)  
**🐙 GitHub:** [HackerX-47](https://github.com/HackerX-47)  
**🔗 LinkedIn:** [Omkar Singh](https://www.linkedin.com/in/omkar-singh-ba2653381/)  
**💻 LeetCode:** [HackerX_47](https://leetcode.com/u/HackerX_47/)
