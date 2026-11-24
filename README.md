# -Student-Grade-Management-System-
A menu-driven Student Grade Management System developed in C language using structures, arrays, functions, loops, and conditional statements.
# Student Grade Management System

## About the Project
The Student Grade Management System is a menu-driven console application developed using the C programming language. It helps manage student records, store marks for five subjects, calculate percentages and grades, and display student results.

This project was developed as a beginner-level C programming project to understand the practical application of fundamental programming concepts.

## Features
- Add student records
- Display all student records
- Search students by roll number
- Calculate total marks
- Calculate percentage
- Assign grades automatically
- Check pass or fail status
- Input validation for marks
- Prevent duplicate roll numbers

## Subjects
1. Mathematics
2. Physics
3. Chemistry
4. English
5. Computer

Each subject is evaluated out of 100 marks.

## Grading System

| Percentage | Grade |
|---|---|
| 90–100 | A |
| 80–89.99 | B |
| 70–79.99 | C |
| 60–69.99 | D |
| 40–59.99 | E |
| Below 40 | F |

A student must score at least 40 in every subject to pass.

## C Concepts Used
- Structures (`struct`)
- Arrays
- Functions
- Loops (`for`, `while`)
- Conditional statements (`if-else`, `switch`)
- User input and output (`scanf`, `printf`, `fgets`)
- Searching
- Input validation

## Modules
1. Menu System
2. Student Data Structure
3. Add Student Record
4. Display All Students
5. Student Result Calculation
6. Search Student by Roll Number

## How to Run

### Using GCC
```bash
gcc main.c -o student_grade
./student_grade
```

### Using Code::Blocks
1. Open Code::Blocks.
2. Create a C project or open the source file.
3. Add `main.c`.
4. Build and Run the program.

## Limitations
- Student records are stored temporarily in memory.
- Records are lost when the program exits.
- Maximum capacity is 100 students.
- No graphical user interface.

## Future Improvements
- File handling for permanent data storage
- Update and delete student records
- Class average and topper calculation
- Better input validation
- Database integration
- GUI interface

## Author
Developed as a first-year engineering C programming project.

## Project Status
Version 1.0 — Modules 1–6 implemented.
