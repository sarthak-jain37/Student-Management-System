#include <stdio.h>
#define MAX_SIZE 500    // Maximum number of students

typedef struct Students     // Structure to define a student
{
    char name[50];          // Student name
    int rollNo;             // Student Roll number
    char address[100];      // Student address
    char phoneNo[11];       // Student phone number
    int marks;              // Student marks in ICP
} Student;

int checkRollNo(Student *students, int n, int rollNo)   // Function to check if a Roll number exists
{
    int left = 0, right = n - 1;                        // Using Binary search 

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (students[mid].rollNo == rollNo)
        {
            return 0;                                   // Roll Number found, hence invlaid 
        }
        else if (students[mid].rollNo < rollNo)
        {
            left = mid + 1;                             // Search right half
        }
        else if (students[mid].rollNo > rollNo)
        {
            right = mid - 1;                            // Search left half
        }
    }
    return 1;                                           // The roll number is unique
}

void addStudent(Student *students, int *n)              // Function to add a new Student to the database
{
    if (*n >= MAX_SIZE)                                 // Checks for space for another student 
    {
        printf("Cannot add more students. Maximum capacity reached.\n");
        return;                             
    }

    Student stud;                                       // Temporary student type variable
    printf("Enter the name of the Student: ");
    scanf(" %[^\n]", stud.name);
    printf("Enter %s's Roll number: ", stud.name);
    scanf(" %d", &stud.rollNo);
    while (!checkRollNo(students, *n, stud.rollNo))     // Ensures that a unique Roll Number has been entered
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
    while (stud.marks < 0 || stud.marks > 100)          // Checks if the marks entered are valid
    {
        printf("Invalid Marks.\n");
        printf("Enter Student's marks in ICP: ");
        scanf(" %d", &stud.marks);
    }
    students[(*n)++] = stud;                            // Adds the student to the array 
}

void displayStudent(Student stud)                       // Function to Display the Student details
{
    printf("\nName of the student: %s\n", stud.name);
    printf("Roll Number: %d\n", stud.rollNo);
    printf("Address: %s\n", stud.address);
    printf("Phone Number: %s\n", stud.phoneNo);
    printf("Marks in ICP: %d\n\n", stud.marks);
}

void sortStudent(Student *students, int n)              // Sorts the Student data using Insertion Sort
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

int searchStudent(Student *students, int n, int key)    //  Binary search to find a student by roll number
{
    int left = 0, right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (students[mid].rollNo == key)
        {
            return mid;                                 // Roll Number found
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
    return -1;                                          // Roll number not found
}

void deleteStudent(Student *students, int *n, int index)    // Function to delete a Student 
{
    for (int i = index; i < *n - 1; i++)
    {
        students[i] = students[i + 1];                      // Shifts all elements to the left by 1 position to remove the student
    }
    (*n)--;                                                 // Decrement student count
    printf("Deletion Succesful! \n\n");
}

void updateEntry(Student *students, int idx, int n, int entry)  // Function to update Student details
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

void findMarks(Student *students, int n, int key)           // Finds the marks of the student by roll number
{
    int idx = searchStudent(students, n, key);
    if(idx < 0){
        return;
    }
    printf("\nName: %s \n", students[idx].name);
    printf("Roll Number: %d \n", students[idx].rollNo);
    printf("Marks: %d \n", students[idx].marks);
}

int main()
{
    int size = 0;                     // Initialize size as 0
    Student students[MAX_SIZE];       // Array to store students

    // Pre - defined Students
    students[size++] = (Student){"Henry", 108, "890 Elm St", "4443332221", 82};
    students[size++] = (Student){"Eva", 105, "654 Birch Blvd", "8887776666", 88};
    students[size++] = (Student){"Alice", 101, "123 Main Street", "9876543210", 90};
    students[size++] = (Student){"Jack", 110, "210 Walnut Rd", "9998887776", 87};
    students[size++] = (Student){"Charlie", 103, "789 Pine Rd", "5551234567", 92};
    students[size++] = (Student){"Grace", 107, "345 Cedar Lane", "6665554443", 95};
    students[size++] = (Student){"Frank", 106, "987 Birch Way", "7890123456", 80};
    students[size++] = (Student){"David", 104, "321 Maple Dr", "7778889999", 78};
    students[size++] = (Student){"Ivy", 109, "567 Spruce Ct", "3332221110", 89};
    students[size++] = (Student){"Bob", 102, "456 Oak Ave", "1234567890", 85};
    sortStudent(students, size);    // Sorting the array

    int action;      // Stores the action to be performed 
    printf("Welcome to the Student Management System!\n");
    printf("Choose one of the following actions:\n");
    printf("1. Add student \t 2. Search Student \t 3. Find ICP Marks of a Student \t 4. Count Students \t 5. Delete Student \t 6. Update a Student's data \t 7. Display Students \t 8. Exit\n");
    scanf(" %d", &action);
    printf("\n");

    while (action != 8)       // Loop until the user chooses to exit 
    {
        int choice;
        int idx;
        int rollno;        
        char confirm;
        switch (action)
        {
        case 1:               // Add a new Student
            addStudent(students, &size);
            sortStudent(students, size);    // Sort after adding a Student
            break;

        case 2:             // Search for a Student by Roll Number 
            printf("Please enter the Student's Roll Number: ");
            scanf(" %d", &rollno);
            idx = searchStudent(students, size, rollno);

            if (idx >= 0)    // Displays the Student details only if the roll number exists 
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
        }
        printf("\nChoose one of the following actions:\n");
        printf("1. Add Student \t 2. Search Student \t 3. Find Marks of a Student \t 4. Count Students \t 5. Delete Student \t 6. Update Entry \t 7. Display Students \t 8. Exit\n");
        scanf(" %d", &action);
    }
    return 0;
}