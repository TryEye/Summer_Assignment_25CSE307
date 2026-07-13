#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50

struct Student 
{
    int  rollNo;
    char name[100];
    int  age;
    float marks;
};

void displayStudent(struct Student s) 
{
    printf("Roll No : %d\n", s.rollNo);
    printf("Name    : %s\n", s.name);
    printf("Age     : %d\n", s.age);
    printf("Marks   : %.2f\n", s.marks);
}

int main()
{
    struct Student students[MAX_STUDENTS];
    int count = 0, choice;

    do
    {
        printf("\n===== Student Record Management =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Roll No\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1)
        {
            if (count >= MAX_STUDENTS)
            {
                printf("Record full!\n");
            } 
            else
            {
                printf("Enter Roll No: ");
                scanf("%d", &students[count].rollNo);
                getchar();
                printf("Enter Name: ");
                fgets(students[count].name, 100, stdin);
                int len = 0;
                while (students[count].name[len] != '\0' && students[count].name[len] != '\n') len++;
                students[count].name[len] = '\0';
                printf("Enter Age: ");
                scanf("%d", &students[count].age);
                printf("Enter Marks: ");
                scanf("%f", &students[count].marks);
                getchar();
                count++;
                printf("Student added successfully!\n");
            }

        } 
        else if (choice == 2)
        {
            if (count == 0)
            {
                printf("No records found.\n");
            } 
            else
            {
                for (int i = 0; i < count; i++)
                {
                    printf("\n--- Student %d ---\n", i + 1);
                    displayStudent(students[i]);
                }
            }

        } 
        else if (choice == 3)
        {
            int roll;
            printf("Enter Roll No to search: ");
            scanf("%d", &roll);
            getchar();
            int found = 0;
            for (int i = 0; i < count; i++)
            {
                if (students[i].rollNo == roll)
                {
                    printf("\n--- Found ---\n");
                    displayStudent(students[i]);
                    found = 1;
                    break;
                }
            }
            if (!found) printf("Student with Roll No %d not found.\n", roll);

        } 
        else if (choice == 4)
        {
            printf("Exiting Student Record System.\n");
        } 
        else
        {
            printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}
