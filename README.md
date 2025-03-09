# Student Management System

## Overview
The **Student Management System** is a C program designed to efficiently manage student information. It provides functionalities such as adding, displaying, searching, updating, and deleting student records. Additionally, it includes features for calculating the average GPA and finding the student with the highest GPA. The system leverages fundamental programming concepts such as conditions, loops, structs, pointers, and linked lists.

## Features
- **Add a Student**: Allows users to enter and store student details.
- **Display All Students**: Lists all students currently stored in the system.
- **Search for a Student by ID**: Finds and displays a specific student’s information using their unique ID.
- **Update Student Information**: Enables modifications to a student’s details.
- **Delete a Student**: Removes a student’s record from the system.
- **Calculate Average GPA**: Computes and displays the average GPA of all students.
- **Find Student with Highest GPA**: Identifies and presents the student with the highest GPA.
- **Exit**: Terminates the program.

## Implementation Details
The program stores student data in a **linked list**, where each student is represented as a node containing:
- **Student ID**
- **Student Name**
- **Age**
- **GPA**
- **Pointer to the next student in the list**

### State Machine Representation
The system operates as a state machine, continuously accepting user inputs and executing the corresponding function based on the selected menu option.

## Function Descriptions

### `int main(void)`
- Displays the menu and processes user choices.
- Calls the relevant function based on user input.
- Runs in a loop until the user chooses to exit.

### `void addStudent(const struct student *const ptr)`
- Collects and validates student details.
- Ensures unique student ID before adding to the list.
- Allocates memory dynamically and appends the student to the linked list.

### `void displayStudents(void)`
- Traverses the linked list and displays all stored student records.
- If no students are present, displays a message indicating an empty list.

### `void searchStudentByID(int id)`
- Searches for a student by ID.
- Displays student details if found; otherwise, indicates the student was not found.

### `void updateStudent(int id)`
- Searches for a student by ID.
- If found, allows modification of the student’s name, age, or GPA.
- Displays an error message if the student is not found.

### `float calculateAverageGPA(void)`
- Traverses the linked list to compute the total GPA.
- Returns the average GPA by dividing the total sum by the number of students.
- If no students exist, returns `0.0`.

### `void searchHighestGPA(void)`
- Finds the student with the highest GPA.
- If multiple students share the highest GPA, the first encountered student is displayed.
- If no students exist, displays an appropriate message.

### `void deleteStudent(int id)`
- Searches for a student by ID.
- If found, removes the student from the linked list and frees allocated memory.
- If not found, displays an error message.

## Technologies Used
- **Programming Language**: C
- **Data Structure**: Linked List
- **Concepts**: Pointers, Memory Allocation, Structs, Functions, Loops, Conditionals
