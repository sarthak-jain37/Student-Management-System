# Student Management System

## Description

The Student Management System, built in C, enables users to add, search, delete, update, and display student information. It maintains a record of students, including their name, roll number, address, phone number, and marks in the subject Introduction to Computing and Programming (ICP). The system supports saving and loading student data from CSV files. It also sorts students by roll number and allows updating individual student details, such as name, roll number, address, phone number, and marks.

## Key Features

- **Modular Design**: Organized into functions like `addStudent()`, `deleteStudent()`, and `sortStudent()` to enhance readability and maintainability.
- **Data Persistence**: Supports saving and loading data from CSV files, preserving changes across sessions.
- **User Interaction**: Clear prompts and descriptive messages guide users, minimizing confusion.
- **Error Handling**: Validates inputs (marks, roll numbers, indices) to prevent crashes or unintended behavior.
- **Critical Action Confirmation**: Asks for confirmation before deleting data or exiting, minimizing the risk of mistakes.
- **Efficiency**: Uses binary search (O(log n)) for searching and insertion sort (O(n²)) for sorting, optimizing operations for small datasets.
- **Scalability**: Handles up to 500 students by default (adjustable via `MAX_SIZE`).
- **Real-Time Updates**: Automatically re-sorts the list after updates, ensuring accurate data handling.
- **Efficient Deletion**: Implements in-place deletion, optimizing memory usage by shifting records rather than leaving gaps.
- **Cross-Platform**: Works on any platform supporting GCC or Clang compilers.


## Installation Steps

1. **Clone the repository:**
   ```bash
   git clone https://github.com/sarthak-jain37/Student-Management-System.git

2. Navigate into the project directory:
   ```bash
   cd student-management-system

3. Compile the C files:
   ```bash
   gcc main.c student.c -o student-management-system
   
4. Run the program:
   ```bash
   ./student-management-system
  
