#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>

typedef struct Students // Structure to define a student
{
    char name[50];     // Student name
    int rollNo;        // Student Roll number
    char address[100]; // Student address
    char phoneNo[11];  // Student phone number
    int marks;         // Student marks in ICP
} Student;

Student *loadStudentsFromCSV(Student *students, int *n, const char *filename);
void saveStudentsToCSV(Student *students, int n, const char *filename);
int checkRollNo(Student *students, int n, int rollNo);          // Function to check if a Roll number exists
void addStudent(Student *students, int *n, const int MAX);      // Function to add a new Student to the database
void displayStudent(Student stud);                              // Function to Display the Student details
void sortStudent(Student *students, int n);                     // Sorts the Student data using Insertion Sort
int searchStudent(Student *students, int n, int key);           // Binary search to find a student by roll number
void deleteStudent(Student *students, int *n, int index);       // Function to delete a Student
void updateEntry(Student *students, int idx, int n, int entry); // Function to update Student details
void findMarks(Student *students, int n, int key);              // Finds the marks of the student by roll number

#endif