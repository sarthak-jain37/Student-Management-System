#include "student.h"

Student *loadStudentsFromCSV(Student *students, int *n, const char *filename) // Function to load student records from a CSV file
{
    FILE *file = fopen(filename, "r");          // Opens the file for reading
    if (!file)                                  // Checks if the file is successfully opened 
    {
        printf("Error opening file!\n");        // If the file doesn't open, display error message
        return NULL;                            // Return NULL to indicate failure
    }

    Student stud;                               // Temporary variable to store the student 

    char line[200];                             // Array to hold each line read from the file

    while (fgets(line, sizeof(line), file))     // Loop to read each line from the CSV file
    {
        if (sscanf(line, "%49[^,],%d,%99[^,],%10[^,],%d", stud.name, &stud.rollNo, stud.address, stud.phoneNo, &stud.marks) == 5)
        {
            students[(*n)++] = stud;
        }
    }
    fclose(file);                                // Close the file after reading
    return students;                             // Return the students array with the loaded data
}

void saveStudentsToCSV(Student *students, int n, const char *filename)  // Function to save student records to a CSV file
{
    FILE *file = fopen(filename, "w");      // Open the file for writing
    if (!file)
    {
        printf("Error opening file!\n");    // Display error message if the file can't be opened
        return;
    }
    fprintf(file, "Name,RollNo,Address,PhoneNo,Marks\n");   // CSV header

    for (int i = 0; i < n; i++)
    {
        fprintf(file, "%s,%d,%s,%s,%d\n", students[i].name, students[i].rollNo, students[i].address, students[i].phoneNo, students[i].marks);
    }

    fclose(file);       // Closes the file after writing 
}

int checkRollNo(Student *students, int n, int rollNo) // Function to check if a Roll number exists
{
    int left = 0, right = n - 1;    // Using Binary search

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (students[mid].rollNo == rollNo)
        {
            return 0;   // Roll Number found, hence invalid
        }
        else if (students[mid].rollNo < rollNo)
        {
            left = mid + 1;     // Search right half
        }
        else if (students[mid].rollNo > rollNo)
        {
            right = mid - 1;    // Search left half
        }
    }
    return 1;   // The roll number is unique
}

void addStudent(Student *students, int *n, const int MAX) // Function to add a new Student to the database
{
    if (*n >= MAX) // Checks for space for another student
    {
        printf("Cannot add more students. Maximum capacity reached.\n");
        return;
    }

    Student stud; // Temporary student type variable
    printf("Enter the name of the Student: ");
    scanf(" %[^\n]", stud.name);
    printf("Enter %s's Roll number: ", stud.name);
    scanf(" %d", &stud.rollNo);
    while (!checkRollNo(students, *n, stud.rollNo)) // Ensures that a unique Roll Number has been entered
    {
        printf("Another Student has already been assigned that Roll Number.\n");
        printf("Enter %s's Roll number: ", stud.name);
        scanf(" %d", &stud.rollNo);
    }
    printf("Enter %s's Address: ", stud.name);
    scanf(" %[^\n]", stud.address);
    printf("Enter %s's Phone Number: ", stud.name);
    scanf(" %[^\n]", stud.phoneNo);
    printf("Enter %s's marks in ICP: ", stud.name);
    scanf(" %d", &stud.marks);
    while (stud.marks < 0 || stud.marks > 100) // Checks if the marks entered are valid
    {
        printf("Invalid Marks.\n");
        printf("Enter Student's marks in ICP: ");
        scanf(" %d", &stud.marks);
    }
    students[(*n)++] = stud; // Adds the student to the array
}

void displayStudent(Student stud) // Function to Display the Student details
{
    printf("\nName of the student: %s\n", stud.name);
    printf("Roll Number: %d\n", stud.rollNo);
    printf("Address: %s\n", stud.address);
    printf("Phone Number: %s\n", stud.phoneNo);
    printf("Marks in ICP: %d\n\n", stud.marks);
}

void sortStudent(Student *students, int n) // Sorts the Student data using Insertion Sort
{
    for (int i = 1; i < n; i++)
    {
        Student key = students[i];
        int j = i - 1;
        while ((j >= 0) && (students[j].rollNo > key.rollNo))
        {
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = key;
    }
}

int searchStudent(Student *students, int n, int key) // Binary search to find a student by roll number
{
    int left = 0, right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (students[mid].rollNo == key)
        {
            return mid; // Roll Number found
        }
        else if (students[mid].rollNo < key)
        {
            left = mid + 1;
        }
        else if (students[mid].rollNo > key)
        {
            right = mid - 1;
        }
    }
    printf("Student with Roll Number %d was not found.\n", key);
    return -1; // Roll number not found
}

void deleteStudent(Student *students, int *n, int index) // Function to delete a Student
{
    if (*n == 0)
    {
        printf("The database is empty.\n");
        return;
    }
    for (int i = index; i < *n - 1; i++)
    {
        students[i] = students[i + 1]; // Shifts all elements to the left by 1 position to remove the student
    }

    students[*n] = (Student){0};
    (*n)--; // Decrement student count
    printf("Deletion Succesful! \n\n");
}

void updateEntry(Student *students, int idx, int n, int entry) // Function to update Student details
{

    switch (entry)
    {

        int rollNo;
    case 1:
        printf("Enter Students's name: ");
        scanf(" %[^\n]", students[idx].name);
        printf("Name Updated.\n");
        break;

    case 2:
        printf("Enter Student's Roll Number: ");
        scanf(" %d", &rollNo);
        while (!checkRollNo(students, n, rollNo))
        {
            printf("Another Student has already been assigned that Roll Number.\n");
            printf("Enter Student's Roll number: ");
            scanf(" %d", &rollNo);
        }
        students[idx].rollNo = rollNo;
        printf("Roll No. Updated.\n");
        break;

    case 3:
        printf("Enter Student's Address: ");
        scanf(" %[^\n]", students[idx].address);
        printf("Address Updated.\n");
        break;

    case 4:
        printf("Enter Student's Phone Number: ");
        scanf(" %[^\n]", students[idx].phoneNo);
        printf("Phone Number Updated.\n");
        break;

    case 5:
        printf("Enter Student's marks in ICP: ");
        scanf(" %d", &students[idx].marks);
        while (students[idx].marks < 0 || students[idx].marks > 100)
        {
            printf("Invalid Marks.\n");
            printf("Enter Student's marks in ICP: ");
            scanf(" %d", &students[idx].marks);
        }

        printf("Marks Updated.\n");
        break;

    default:
        printf("Invalid Entry\n");
        break;
    }
}

void findMarks(Student *students, int n, int key) // Finds the marks of the student by roll number
{
    int idx = searchStudent(students, n, key);
    if (idx < 0)
    {
        return;
    }
    printf("\nName: %s \n", students[idx].name);
    printf("Roll Number: %d \n", students[idx].rollNo);
    printf("Marks: %d \n", students[idx].marks);
}