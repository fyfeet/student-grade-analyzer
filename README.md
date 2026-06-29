# Student Grade Analyzer

## Group Project

### Project Overview

The **Student Grade Analyzer** is a C programming project designed to manage and analyze student grades. The program allows users to enter student information and scores, then automatically calculates averages, assigns grades, determines rankings, identifies the highest and lowest scores, and generates pass/fail reports.

This project demonstrates the use of fundamental C programming concepts, including arrays, functions, sorting algorithms, and file handling.

---

## Features

* Add student records
* Store student information in files
* Load existing student records
* Calculate each student's average score
* Assign letter grades
* Determine pass/fail status
* Find the highest and lowest scoring students
* Rank students based on average scores
* Display a formatted student report

---

## Programming Concepts Used

* Arrays
* Structures (`struct`)
* Functions
* Sorting Algorithms
* File Handling (`fopen`, `fclose`, `fprintf`, `fscanf`)
* Loops
* Conditional Statements

---

## Project Structure

```text
Student-Grade-Analyzer/
│
├── main.c              # Main program
├── students.txt        # Student data file
├── README.md           # Project documentation
└── (optional headers/source files)
```

---

## Team Members

| Member   | Responsibility                                                                 |
| -------- | ------------------------------------------------------------------------------ |
| Member 1 | Define the `Student` structure, global variables, constants, and project setup |
| Member 2 | Input student information and save/load data using file handling               |
| Member 3 | Calculate averages, total scores, and assign letter grades                     |
| Member 4 | Determine pass/fail status and find highest/lowest scores                      |
| Member 5 | Sort students by average score and assign rankings                             |
| Member 6 | Create the menu system, integrate all modules, testing, and debugging          |

---

## How to Compile

Using GCC:

```bash
gcc main.c -o StudentGradeAnalyzer
```

Run:

```bash
./StudentGradeAnalyzer
```

On Windows:

```bash
StudentGradeAnalyzer.exe
```

---

## Sample Functions

* `inputStudents()`
* `saveToFile()`
* `loadFromFile()`
* `calculateAverage()`
* `assignGrade()`
* `rankStudents()`
* `findHighestScore()`
* `findLowestScore()`
* `displayReport()`

---

## Learning Objectives

After completing this project, students will gain experience with:

* Working with arrays of structures
* Creating modular programs using functions
* Reading from and writing to files
* Implementing sorting algorithms
* Organizing larger programs as a team
* Using Git and GitHub for collaboration

---

## License

This project was developed as part of a university coursework assignment and is intended for educational purposes only.
