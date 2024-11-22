#include <stdio.h>
#include "student.h"
#define MAX_SIZE 500 // Maximum number of students

int main()
{
    int size = 0;               // Initialize size as 0
    Student students[MAX_SIZE]; // Array to store students

    loadStudentsFromCSV(students, &size, "students.csv");
    sortStudent(students, size); // Sorting the array

    int action; // Stores the action to be performed
    printf("Welcome to the Student Management System!\n");
    printf("Choose one of the following actions:\n");
    printf("1. Add student \t 2. Search Student \t 3. Find ICP Marks of a Student \t 4. Count Students \t 5. Delete Student \t 6. Update a Student's data \t 7. Display Students \t 8. Exit\n");
    scanf(" %d", &action);
    printf("\n");

    while (1) // Loop until the user chooses to exit
    {
        if (action == 8)
        {
            char confirm;
            printf("Do you want to save your changes (Y / N): ");
            scanf(" %c", &confirm);
            if (confirm == 'Y' || confirm == 'y')
            {
                saveStudentsToCSV(students, size, "students.csv");
            }
            break;
        }

        int choice;
        int idx;
        int rollno;
        char confirm;
        switch (action)
        {
        case 1: // Add a new Student
            addStudent(students, &size, MAX_SIZE);
            sortStudent(students, size); // Sort after adding a Student
            break;

        case 2: // Search for a Student by Roll Number
            printf("Please enter the Student's Roll Number: ");
            scanf(" %d", &rollno);
            idx = searchStudent(students, size, rollno);

            if (idx >= 0) // Displays the Student details only if the roll number exists
                displayStudent(students[idx]);
            break;

        case 3:
            printf("Please enter the Student's Roll Number: ");
            scanf(" %d", &rollno);
            findMarks(students, size, rollno);
            break;

        case 4:
            printf("The number of students is: %d\n", size);
            break;

        case 5:
            printf("Enter the Roll Number of the Student to be deleted (Enter 0 to cancel deletion): ");
            scanf(" %d", &choice);
            if (choice == 0)
            {
                break;
            }

            idx = searchStudent(students, size, choice);
            if (idx == -1)
            {
                break;
            }
            displayStudent(students[idx]);
            printf("Are you sure you want to delete this Student (Y / N) :");
            scanf(" %c", &confirm);
            if (confirm == 'Y' || confirm == 'y')
            {
                deleteStudent(students, &size, idx);
            }
            break;

        case 6:
            printf("Enter the Roll Number of the Student to be updated (Enter 0 to cancel update): ");
            scanf(" %d", &choice);
            if (choice == 0)
            {
                break;
            }

            idx = searchStudent(students, size, choice);
            if (idx == -1)
            {
                break;
            }
            displayStudent(students[idx]);
            int entry;
            printf("Which Entry would you like to update- 1. Name \t 2. Roll Number \t 3. Address \t 4. Phone Number \t 5. ICP Marks \t 6. Exit\n");
            scanf("%d", &entry);
            if (entry != 6)
            {
                updateEntry(students, idx, size, entry);
                sortStudent(students, size);
            }
            break;

        case 7:
            for (int i = 0; i < size; i++)
            {
                displayStudent(students[i]);
            }
            break;
        }
        printf("\nChoose one of the following actions:\n");
        printf("1. Add Student \t 2. Search Student \t 3. Find Marks of a Student \t 4. Count Students \t 5. Delete Student \t 6. Update Entry \t 7. Display Students \t 8. Exit\n");
        scanf(" %d", &action);
    }
    return 0;
}