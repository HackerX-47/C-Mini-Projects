# Student Marks Analyzer

A C program that allows teachers or administrators to input student marks for multiple subjects and generates a detailed report with totals, percentages, grades, pass/fail status, and class statistics.

---

## 🧩 Features

- Input marks for any number of students and subjects.
- Calculates **total marks** and **percentage** for each student.
- Assigns **grades** based on percentage:
  - `X` (90%+), `A` (80–89%), `B` (70–79%), `C` (60–69%), `D` (50–59%), `E` (33.33–49%), `F` (<33.33%)
- Determines **pass/fail status** for each student.
- Identifies **highest and lowest marks** for each subject.
- Calculates **class average**.
- Identifies **class toppers**, including multiple toppers if percentages match.
- Provides an easy-to-follow interactive **instructions menu**.

---

## ⚙️ Requirements

- C Compiler (e.g., `gcc`)
- Command-line interface / terminal
- Basic knowledge of C programming to run the program

---

## 💻 Compilation & Execution

1. **Clone or download** this repository.
2. **Open terminal/command prompt** in the project folder.
3. **Compile** the program:

```bash
gcc student_marks_analyzer.c -o student_marks_analyzer
```

## Run the compiled program:

```bash
./student_marks_analyzer   # Linux / macOS
student_marks_analyzer.exe # Windows
```
## Follow the on-screen instructions to input data and view the report.

## 📘 Usage Example

```bash
---- Students Marks Analyzer ----
==============================================
Welcome to the Student Marks Analyzer Program!
...
Enter Your Choice (0 or 1) :- 1
Number of students in class = 3
Number of subjects = 2

Enter name of student :- Alice
Enter roll number of student :- 101
Enter Alice marks of subject 1 :- 95
Enter Alice marks of subject 2 :- 88
...

```
### The program then outputs a formatted report:

```bash
Name                    Roll Number  Subject1  Subject2  Total Marks  Percent  Result  Grade
Alice                   101          95.00     88.00     183.00       91.50    PASS    X
...
Class Average = 75.33
Class topper :- Alice 91.50%
```

## 📊 Output Details

-> Student Table: Displays marks for all subjects, total, percentage, result, and grade.
-> Subject Stats: Shows the highest and lowest marks per subject.
-> Class Stats: Displays overall class average and the list of toppers.

## 📝 Notes

-> Marks must be between 0 and 100 inclusive.
-> Failing in any subject results in an overall FAIL.
-> Multiple students with the same highest percentage are all listed as toppers.

## 👨‍💻 Author

This project was created by **Omkar**<br>
**📧 Email:** [omkar121207@gmail.com](mailto:omkar121207@gmail.com)  
**🐙 GitHub:** [HackerX-47](https://github.com/HackerX-47)<br>
**🔗 LinkedIn:** [Omkar Singh](https://www.linkedin.com/in/omkar-singh-ba2653381/)  
**💻 LeetCode:** [HackerX_47](https://leetcode.com/u/HackerX_47/)