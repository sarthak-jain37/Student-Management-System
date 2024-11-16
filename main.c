#include <stdio.h>
#define MAX_SIZE 100

typedef struct Students
{
    char name[50];
    int rollNo;
    char address[100];
    char phoneNo[10];
    int marks;
} Student;

Student addStudent()
{
    Student stud;
    printf("Enter the name of the Student: ");
    scanf(" %[^\n]", stud.name);
    printf("Enter %s's Roll Number: ", stud.name);
    scanf(" %d", &stud.rollNo);
    printf("Enter %s's Address: ", stud.name);
    scanf(" %[^\n]", stud.address);
    printf("Enter %s's Phone Number: ", stud.name);
    scanf(" %[^\n]", stud.phoneNo);
    printf("Enter %s's marks in ICP: ", stud.name);
    scanf(" %d", &stud.marks);
    return stud;
}

void displayStudent(Student stud)
{
    printf("Name of the Student: %s\n", stud.name);
    printf("Roll Number: %d\n", stud.rollNo);
    printf("Address: %s\n", stud.address);
    printf("Phone Number: %s\n", stud.phoneNo);
    printf("Marks in ICP: %d\n\n", stud.marks);
}

void sortStudents(Student *students, int n)
{
    for (int i = 1; i < n; i++)
    {
        Student key = students[i];
        int j = i - 1;
        while (j >= 0 && students[j].rollNo > key.rollNo)
        {
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = key;
    }
}

void searchStudent(int key, Student students[], int n)
{
    int left = 0, right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (students[mid].rollNo == key)
        {
            displayStudent(students[mid]);
            return;
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
    printf("Student with Roll Number: %d was not found.\n", key);
}

void deleteStudent(int choice, Student *students, int *n)
{

    for (int i = choice; i < *n - 1; i++)
    {
        students[i] = students[i + 1];
    }

    (*n)--;
    printf("Deletion Successful! \n\n");
}

void updateEntry(Student *student, int entry)
{
    switch (entry)
    {
    case 1:
        printf("Enter Student's name: ");
        scanf(" %[^\n]", student->name);
        break;

    case 2:
        printf("Enter Student's Roll Number: ");
        scanf(" %d", &student->rollNo);
        break;

    case 3:
        printf("Enter Student's Address: ");
        scanf(" %[^\n]", student->address);
        break;

    case 4:
        printf("Enter Student's Phone Number: ");
        scanf(" %[^\n]", student->phoneNo);
        break;

    case 5:
        printf("Enter Student's marks in ICP: ");
        scanf(" %d", &student->marks);
        break;

    default:
        printf("Invalid entry.\n");
        break;
    }
}

int main()
{
    int size = 0;
    Student students[MAX_SIZE];
    students[0] = (Student){"Alice", 101, "123 Main St", "9876543210", 90};
    students[1] = (Student){"Bob", 102, "456 Oak Ave", "1234567890", 85};
    students[2] = (Student){"Charlie", 103, "789 Pine Rd", "5551234567", 92};
    students[3] = (Student){"David", 104, "321 Maple Dr", "7778889999", 78};
    students[4] = (Student){"Eva", 105, "654 Birch Blvd", "8887776666", 88};
    students[5] = (Student){"Frank", 106, "987 Birch Way", "7890123456", 80};
    size = 6;

    int action;
    printf("Welcome to the Student Management System!\n");
    printf("Choose one of the following actions:\n");
    printf("1. Add Student \t 2. Search Student \t 3. Find ICP Marks of a Student \t 4. Count Students \t 5. Delete Student \t 6. Update a Student's Data 7. Exit\n");
    scanf("%d", &action);
    while (action != 7)
    {
        switch (action)
        {
        case 1:
            students[size++] = addStudent();
            sortStudents(students, size);
            break;

        case 2:
            int rollno;
            printf("Please enter the Student's Roll Number: ");
            scanf("%d", &rollno);
            searchStudent(rollno, students, size);
            break;

        case 3:
            break;

        case 4:
            printf("The number of Students is: %d\n", size);
            break;

        case 5:
            printf("The students are: \n");
            for (int i = 0; i < size; i++)
            {
                printf("%d:\n", i + 1);
                displayStudent(students[i]);
            }
            printf("0. Exit\n");
            int choice;
            printf("Which Student would you like to delete: ");
            scanf("%d", &choice);
            if (choice == 0)
                break;
            else if (choice < 0 || choice > size)
            {
                printf("Invalid choice! No student deleted.\n");
                break;
            }
            printf("Deleting %s...\n", students[choice - 1].name);
            deleteStudent(choice - 1, students, &size);
            break;

        case 6:
            printf("The students are: \n");
            for (int i = 0; i < size; i++)
            {
                printf("%d:\n", i + 1);
                displayStudent(students[i]);
            }
            int student;
            printf("Which Student's would you like to update: ");
            scanf("%d", &student);
            if (student > size)
            {
                break;
            }
            int entry;
            displayStudent(students[student - 1]);
            printf("Which Entry would you like to update- 1. Name \t 2. Roll Number \t 3. Address \t 4. Phone Number \t 5. ICP Marks \t 6. Exit");
            scanf("%d", &entry);
            if (entry != 6)
            {
                updateEntry(&students[student - 1], entry);
            }
        }

        printf("\nChoose one of the following actions:\n");
        printf("1. Add Student \t 2. Search Student \t 3. Find ICP Marks of a Student \t 4. Count Students \t 5. Delete Student \t 6. Update a Student's Data 7. Exit\n");
        scanf("%d", &action);
    }
}