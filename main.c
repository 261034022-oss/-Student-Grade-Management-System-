#include <stdio.h>
#include <string.h>

// MODULE 2: Student Structure
struct Student
{
    int rollNo;
    char name[50];
    float marks[5];
};

// Subject names
const char *subjects[5] =
{
    "Mathematics",
    "Physics",
    "Chemistry",
    "English",
    "Computer"
};

// MODULE 1: Display Menu
void showMenu()
{
    printf("\n=========================================\n");
    printf("       STUDENT GRADE MANAGEMENT SYSTEM\n");
    printf("=========================================\n");

    printf("1. Add Student Record\n");
    printf("2. Display All Student Records\n");
    printf("3. Search Student by Roll Number\n");
    printf("4. Display Student Result\n");
    printf("5. Exit\n");

    printf("-----------------------------------------\n");
    printf("Enter your choice: ");
}

// MODULE 3: Add Student Record
void addStudent(struct Student students[], int *studentCount)
{
    int roll, i, ch;
    float mark;

    if (*studentCount >= 100)
    {
        printf("\nStudent record limit reached!\n");
        return;
    }

    printf("\nEnter Roll Number: ");

    if (scanf("%d", &roll) != 1 || roll <= 0)
    {
        printf("Invalid roll number!\n");

        while ((ch = getchar()) != '\n' && ch != EOF);

        return;
    }

    // Check for duplicate roll number
    for (i = 0; i < *studentCount; i++)
    {
        if (students[i].rollNo == roll)
        {
            printf("Roll number already exists!\n");
            return;
        }
    }

    students[*studentCount].rollNo = roll;

    // Clear input buffer
    while ((ch = getchar()) != '\n' && ch != EOF);

    // Input name
    printf("Enter Student Name: ");

    if (fgets(students[*studentCount].name, 50, stdin) == NULL)
    {
        printf("Error reading name!\n");
        return;
    }

    // Remove newline from name
    students[*studentCount].name[
        strcspn(students[*studentCount].name, "\n")
    ] = '\0';

    // Input marks
    printf("\nEnter marks out of 100:\n");

    for (i = 0; i < 5; i++)
    {
        do
        {
            printf("%s: ", subjects[i]);

            if (scanf("%f", &mark) != 1)
            {
                printf("Invalid input! Enter numeric marks.\n");

                while ((ch = getchar()) != '\n' && ch != EOF);

                mark = -1;
            }

            if (mark < 0 || mark > 100)
            {
                printf("Marks must be between 0 and 100!\n");
            }

        } while (mark < 0 || mark > 100);

        students[*studentCount].marks[i] = mark;
    }

    (*studentCount)++;

    printf("\nStudent record added successfully!\n");
}

// MODULE 4: Display All Student Records
void displayAllStudents(struct Student students[], int studentCount)
{
    int i, j;

    if (studentCount == 0)
    {
        printf("\nNo student records available!\n");
        return;
    }

    printf("\n========== ALL STUDENT RECORDS ==========\n");

    for (i = 0; i < studentCount; i++)
    {
        printf("\nStudent %d\n", i + 1);
        printf("----------------------------------------\n");

        printf("Roll Number: %d\n", students[i].rollNo);
        printf("Name: %s\n", students[i].name);

        printf("Marks:\n");

        for (j = 0; j < 5; j++)
        {
            printf("%s: %.2f\n",
                   subjects[j], students[i].marks[j]);
        }
    }

    printf("\n========================================\n");
}

// MODULE 5: Calculate Total Marks
float calculateTotal(struct Student s)
{
    int i;
    float total = 0;

    for (i = 0; i < 5; i++)
    {
        total = total + s.marks[i];
    }

    return total;
}

// MODULE 5: Calculate Percentage
float calculatePercentage(struct Student s)
{
    float total;

    total = calculateTotal(s);

    return (total / 500.0) * 100;
}

// MODULE 5: Calculate Grade
char calculateGrade(float percentage)
{
    if (percentage >= 90)
        return 'A';

    else if (percentage >= 80)
        return 'B';

    else if (percentage >= 70)
        return 'C';

    else if (percentage >= 60)
        return 'D';

    else if (percentage >= 40)
        return 'E';

    else
        return 'F';
}

// MODULE 5: Check Pass or Fail
int isPass(struct Student s)
{
    int i;

    for (i = 0; i < 5; i++)
    {
        if (s.marks[i] < 40)
        {
            return 0;
        }
    }

    return 1;
}

// MODULE 6: Search Student by Roll Number
void searchStudent(struct Student students[], int studentCount)
{
    int roll, i, ch;
    int found = 0;

    if (studentCount == 0)
    {
        printf("\nNo student records available!\n");
        return;
    }

    printf("\nEnter Roll Number to search: ");

    if (scanf("%d", &roll) != 1)
    {
        printf("Invalid roll number!\n");

        while ((ch = getchar()) != '\n' && ch != EOF);

        return;
    }

    // Linear search
    for (i = 0; i < studentCount; i++)
    {
        if (students[i].rollNo == roll)
        {
            found = 1;

            printf("\n========== STUDENT FOUND ==========\n");

            printf("Roll Number: %d\n", students[i].rollNo);
            printf("Name: %s\n", students[i].name);

            printf("\nSubject Marks:\n");

            for (int j = 0; j < 5; j++)
            {
                printf("%s: %.2f\n",
                       subjects[j], students[i].marks[j]);
            }

            printf("\nTotal Marks: %.2f / 500\n",
                   calculateTotal(students[i]));

            printf("Percentage: %.2f%%\n",
                   calculatePercentage(students[i]));

            printf("Grade: %c\n",
                   calculateGrade(calculatePercentage(students[i])));

            if (isPass(students[i]))
            {
                printf("Status: PASS\n");
            }
            else
            {
                printf("Status: FAIL\n");
            }

            printf("==================================\n");

            break;
        }
    }

    if (found == 0)
    {
        printf("\nStudent not found!\n");
    }
}

// MODULE 5: Display Student Result
void displayResult(struct Student students[], int studentCount)
{
    int roll, i, ch;
    int found = 0;

    if (studentCount == 0)
    {
        printf("\nNo student records available!\n");
        return;
    }

    printf("\nEnter Roll Number to display result: ");

    if (scanf("%d", &roll) != 1)
    {
        printf("Invalid roll number!\n");

        while ((ch = getchar()) != '\n' && ch != EOF);

        return;
    }

    for (i = 0; i < studentCount; i++)
    {
        if (students[i].rollNo == roll)
        {
            found = 1;

            printf("\n========== STUDENT RESULT ==========\n");

            printf("Roll Number: %d\n", students[i].rollNo);
            printf("Name: %s\n", students[i].name);

            printf("\nSubject Marks:\n");

            for (int j = 0; j < 5; j++)
            {
                printf("%s: %.2f\n",
                       subjects[j], students[i].marks[j]);
            }

            printf("\nTotal Marks: %.2f / 500\n",
                   calculateTotal(students[i]));

            printf("Percentage: %.2f%%\n",
                   calculatePercentage(students[i]));

            printf("Grade: %c\n",
                   calculateGrade(calculatePercentage(students[i])));

            if (isPass(students[i]))
            {
                printf("Status: PASS\n");
            }
            else
            {
                printf("Status: FAIL\n");
            }

            printf("===================================\n");

            break;
        }
    }

    if (found == 0)
    {
        printf("\nStudent not found!\n");
    }
}

// MAIN FUNCTION
int main()
{
    struct Student students[100];

    int studentCount = 0;
    int choice;
    int ch;

    do
    {
        showMenu();

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input! Please enter a number.\n");

            while ((ch = getchar()) != '\n' && ch != EOF);

            choice = 0;
        }

        switch (choice)
        {
            case 1:
                addStudent(students, &studentCount);
                break;

            case 2:
                displayAllStudents(students, studentCount);
                break;

            case 3:
                searchStudent(students, studentCount);
                break;

            case 4:
                displayResult(students, studentCount);
                break;

            case 5:
                printf("\nThank you for using the Grade Management System!\n");
                break;

            default:
                printf("\nInvalid choice! Enter a number between 1 and 5.\n");
        }

    } while (choice != 5);

    return 0;
}
