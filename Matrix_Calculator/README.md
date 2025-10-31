# 🔢 Matrix Calculator 💻

This repository contains a C program designed to perform various mathematical operations on matrices. It's built as a menu-driven command-line
application, making it a handy tool for linear algebra computations.

## ✨ Features

The program supports the following matrix operations:

1.  **Addition** of two matrices ($A + B$)
2.  **Subtraction** of two matrices ($A - B$)
3.  **Multiplication** of two matrices ($A \times B$)
4.  **Transpose** of a matrix ($A^T$)
5.  **Determinant** of a square matrix ($|A|$)
6.  **Inverse** of a square matrix ($A^{-1}$)
7.  **Exit** the program

---

## 🛠️ Requirements & Setup

### Requirements

* A C compiler (e.g., GCC)
* Standard C library (`stdio.h`)

### How to Compile and Run

1.  **Save** the C code (the content of your provided file) as `matrix_calculator.c`.
2.  **Compile** the program using a C compiler (like GCC) in your terminal:
    ```bash
    gcc matrix_calculator.c -o matrix_calculator
    ```
3.  **Run** the executable:
    ```bash
    ./matrix_calculator
    ```

---

## 📝 Usage

Upon running, the program displays a menu of available operations.

### Input

The user will be prompted to:

1.  **Select an operation** (by entering the corresponding number).
2.  **Enter the dimensions** (rows and columns) for the required matrix/matrices.
3.  **Input the elements** of the matrix/matrices row-by-row.

The program includes basic validation to ensure matrices meet the mathematical criteria for the chosen operation (e.g., same dimensions for addition/subtraction, compatibility for multiplication, and square matrix check for determinant/inverse).

### Output

The result of the chosen operation is displayed as a matrix, with elements formatted to two decimal places (`.2f`), followed by a success message.

---

## 👨‍💻 Program Structure and Implementation Details

The program is organized using function prototypes for clarity and modularity. Key functions include:

* `instructions()`: Displays the main menu and usage notes.
* `inputMatrix()`: Handles user input for matrix elements.
* `displayMatrix()`: Prints a matrix to the console.
* `addMatrix()`/`subtractMatrix()`: Performs element-wise arithmetic.
* `multiplicationMatrix()`: Implements the standard matrix multiplication algorithm.
* `transposeMatrix()`: Swaps rows and columns to find the transpose.
* `determinant()`: Implements the **Laplace expansion** (cofactor expansion) recursively to calculate the determinant.
* `inverseMatrix()`: Calculates the inverse using the formula: $A^{-1} = \frac{1}{|A|} \cdot \text{adj}(A)$. This involves calculating the determinant and then the **adjoint** matrix (transpose of the cofactor matrix).

---

## 👤 Author

This project was created by **Omkar**<br>
**📧 Email:** [omkar121207@gmail.com](mailto:omkar121207@gmail.com)  
**🐙 GitHub:** [HackerX-47](https://github.com/HackerX-47)<br>
**🔗 LinkedIn:** [Omkar Singh](https://www.linkedin.com/in/omkar-singh-ba2653381/)  
**💻 LeetCode:** [HackerX_47](https://leetcode.com/u/HackerX_47/)
* **Repository Location:** `C-Mini-Projects/Matrix_Calculator`

---