#include <stdio.h>
#include <string.h>

#define MAX 50
#define SUBJECTS 5

char studentNames[MAX][100];
int  rollNumbers[MAX];
float subjectMarks[MAX][SUBJECTS];
int  studentCount = 0;

char subjectNames[SUBJECTS][30] = {"Maths", "Physics", "Chemistry", "English", "CS"};

void addStudent() 
{
    if (studentCount >= MAX)
    { 
        printf("Storage full!\n"); return; 
    }
    int idx = studentCount;
    printf("Enter Roll No: ");
    scanf("%d", &rollNumbers[idx]);
    getchar();
    printf("Enter Name: ");
    fgets(studentNames[idx], 100, stdin);
    int len = 0;
    while (studentNames[idx][len] != '\0' && studentNames[idx][len] != '\n') len++;
    studentNames[idx][len] = '\0';
    printf("Enter marks for 5 subjects:\n");
    for (int i = 0; i < SUBJECTS; i++)
    {
        printf("  %s: ", subjectNames[i]);
        scanf("%f", &subjectMarks[idx][i]);
    }
    getchar();
    studentCount++;
    printf("Student added!\n");
}

void displayAll() 
{
    if (studentCount == 0)
    { 
        printf("No records.\n"); return; 
    }
    printf("\n%-5s %-20s", "Roll", "Name");
    for (int s = 0; s < SUBJECTS; s++) printf(" %-8s", subjectNames[s]);
    printf(" %-8s %-8s\n", "Total", "Grade");
    printf("-------------------------------------------------------------------------------\n");
    for (int i = 0; i < studentCount; i++)
    {
        float total = 0;
        for (int s = 0; s < SUBJECTS; s++) total += subjectMarks[i][s];
        float perc = total / SUBJECTS;
        char grade = (perc >= 90) ? 'A' : (perc >= 75) ? 'B' : (perc >= 60) ? 'C' : (perc >= 45) ? 'D' : 'F';
        printf("%-5d %-20s", rollNumbers[i], studentNames[i]);
        for (int s = 0; s < SUBJECTS; s++) printf(" %-8.1f", subjectMarks[i][s]);
        printf(" %-8.1f %c\n", total, grade);
    }
}

void searchByRoll() 
{
    int roll;
    printf("Enter Roll No: ");
    scanf("%d", &roll);
    getchar();
    for (int i = 0; i < studentCount; i++)
    {
        if (rollNumbers[i] == roll)
        {
            printf("Name: %s\n", studentNames[i]);
            float total = 0;
            for (int s = 0; s < SUBJECTS; s++)
            {
                printf("%s: %.1f\n", subjectNames[s], subjectMarks[i][s]);
                total += subjectMarks[i][s];
            }
            float perc = total / SUBJECTS;
            printf("Total: %.1f | Percentage: %.2f%%\n", total, perc);
            char grade = (perc >= 90) ? 'A' : (perc >= 75) ? 'B' : (perc >= 60) ? 'C' : (perc >= 45) ? 'D' : 'F';
            printf("Grade: %c\n", grade);
            return;
        }
    }
    printf("Student not found.\n");
}

void topStudents() 
{
    if (studentCount == 0)
    { 
        printf("No records.\n"); return; 
    }
    int topIdx = 0;
    float topTotal = 0;
    for (int s = 0; s < SUBJECTS; s++) topTotal += subjectMarks[0][s];
    for (int i = 1; i < studentCount; i++)
    {
        float total = 0;
        for (int s = 0; s < SUBJECTS; s++) total += subjectMarks[i][s];
        if (total > topTotal)
        { 
            topTotal = total; topIdx = i; 
        }
    }
    printf("Top Student: %s (Roll: %d, Total: %.1f)\n",
           studentNames[topIdx], rollNumbers[topIdx], topTotal);
}

int main()
{
    int choice;
    do
    {
        printf("\n===== Student Record System =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Records\n");
        printf("3. Search by Roll No\n");
        printf("4. Find Top Student\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: searchByRoll(); break;
            case 4: topStudents(); break;
            case 5: printf("Exiting Student Record System.\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
