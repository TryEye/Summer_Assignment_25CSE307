#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_STUDENTS 50
#define NUM_SUBJECTS 5

int   rollNo[MAX_STUDENTS];
char  names[MAX_STUDENTS][100];
int   ages[MAX_STUDENTS];
float marks[MAX_STUDENTS][NUM_SUBJECTS];
char  subjects[NUM_SUBJECTS][30] = {"Maths", "Science", "English", "History", "CS"};
int   totalStudents = 0;

float calcTotal(int idx) 
{
    float total = 0;
    for (int s = 0; s < NUM_SUBJECTS; s++) total += marks[idx][s];
    return total;
}

float calcPercentage(int idx) 
{
    return calcTotal(idx) / NUM_SUBJECTS;
}

char calcGrade(float perc) 
{
    if (perc >= 90) return 'A';
    if (perc >= 75) return 'B';
    if (perc >= 60) return 'C';
    if (perc >= 45) return 'D';
    return 'F';
}

int findByRoll(int roll) 
{
    for (int i = 0; i < totalStudents; i++)
    {
        if (rollNo[i] == roll) return i;
    }
    return -1;
}

void addStudent() 
{
    if (totalStudents >= MAX_STUDENTS)
    { 
        printf("Capacity full!\n"); return; 
    }
    int i = totalStudents;
    printf("Enter Roll No: ");
    scanf("%d", &rollNo[i]);
    if (findByRoll(rollNo[i]) != -1)
    { 
        printf("Roll No already exists!\n"); return; 
    }
    getchar();
    printf("Enter Name: ");
    fgets(names[i], 100, stdin);
    int len = 0;
    while (names[i][len] != '\0' && names[i][len] != '\n') len++;
    names[i][len] = '\0';
    printf("Enter Age: ");
    scanf("%d", &ages[i]);
    printf("Enter marks for subjects:\n");
    for (int s = 0; s < NUM_SUBJECTS; s++)
    {
        printf("  %-10s: ", subjects[s]);
        scanf("%f", &marks[i][s]);
    }
    getchar();
    totalStudents++;
    printf("Student added successfully!\n");
}

void viewAllStudents() {
    if (totalStudents == 0)
{ printf("No students found.\n"); return; }
    printf("\n%-5s %-22s %-5s", "Roll", "Name", "Age");
    for (int s = 0; s < NUM_SUBJECTS; s++) printf(" %-8s", subjects[s]);
    printf(" %-8s %-7s %-6s\n", "Total", "Perc%", "Grade");
    printf("------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < totalStudents; i++)
{
        float total = calcTotal(i);
        float perc  = calcPercentage(i);
        printf("%-5d %-22s %-5d", rollNo[i], names[i], ages[i]);
        for (int s = 0; s < NUM_SUBJECTS; s++) printf(" %-8.1f", marks[i][s]);
        printf(" %-8.1f %-7.2f %-6c\n", total, perc, calcGrade(perc));
    }
}

void viewMarksheet() {
    int roll; printf("Enter Roll No: "); scanf("%d", &roll); getchar();
    int idx = findByRoll(roll);
    if (idx == -1)
{ printf("Student not found.\n"); return; }
    float total = calcTotal(idx);
    float perc  = calcPercentage(idx);
    char grade  = calcGrade(perc);
    printf("\n===================== MARKSHEET =====================\n");
    printf("Roll No     : %d\n", rollNo[idx]);
    printf("Name        : %s\n", names[idx]);
    printf("Age         : %d\n", ages[idx]);
    printf("-----------------------------------------------------\n");
    for (int s = 0; s < NUM_SUBJECTS; s++) printf("%-12s : %.1f / 100\n", subjects[s], marks[idx][s]);
    printf("-----------------------------------------------------\n");
    printf("Total       : %.1f / %d\n", total, NUM_SUBJECTS * 100);
    printf("Percentage  : %.2f%%\n", perc);
    printf("Grade       : %c\n", grade);
    printf("Result      : %s\n", grade != 'F' ? "PASS" : "FAIL");
    printf("=====================================================\n");
}

void showToppers() {
    if (totalStudents == 0)
{ printf("No students.\n"); return; }
    int topIdx = 0;
    float topTotal = calcTotal(0);
    for (int i = 1; i < totalStudents; i++)
{
        float t = calcTotal(i);
        if (t > topTotal)
{ topTotal = t; topIdx = i; }
    }
    printf("Class Topper: %s (Roll: %d) | Total: %.1f | Percentage: %.2f%%\n",
           names[topIdx], rollNo[topIdx], topTotal, calcPercentage(topIdx));
}

void classStatistics() {
    if (totalStudents == 0)
{ printf("No students.\n"); return; }
    float totalPerc = 0, maxPerc = calcPercentage(0), minPerc = calcPercentage(0);
    int pass = 0, fail = 0;
    for (int i = 0; i < totalStudents; i++)
{
        float p = calcPercentage(i);
        totalPerc += p;
        if (p > maxPerc) maxPerc = p;
        if (p < minPerc) minPerc = p;
        if (calcGrade(p) != 'F') pass++; else fail++;
    }
    printf("\n===== Class Statistics =====\n");
    printf("Total Students  : %d\n", totalStudents);
    printf("Passed          : %d\n", pass);
    printf("Failed          : %d\n", fail);
    printf("Class Average   : %.2f%%\n", totalPerc / totalStudents);
    printf("Highest Score   : %.2f%%\n", maxPerc);
    printf("Lowest Score    : %.2f%%\n", minPerc);
}

void updateMarks() {
    int roll; printf("Enter Roll No: "); scanf("%d", &roll); getchar();
    int idx = findByRoll(roll);
    if (idx == -1)
{ printf("Student not found.\n"); return; }
    printf("Updating marks for %s:\n", names[idx]);
    for (int s = 0; s < NUM_SUBJECTS; s++)
{
        printf("  %s (current: %.1f): ", subjects[s], marks[idx][s]);
        scanf("%f", &marks[idx][s]);
    }
    getchar();
    printf("Marks updated successfully!\n");
}

void deleteStudent() {
    int roll; printf("Enter Roll No to delete: "); scanf("%d", &roll); getchar();
    int idx = findByRoll(roll);
    if (idx == -1)
{ printf("Student not found.\n"); return; }
    for (int i = idx; i < totalStudents - 1; i++)
{
        rollNo[i] = rollNo[i + 1];
        strcpy(names[i], names[i + 1]);
        ages[i] = ages[i + 1];
        for (int s = 0; s < NUM_SUBJECTS; s++) marks[i][s] = marks[i + 1][s];
    }
    totalStudents--;
    printf("Student deleted successfully.\n");
}

int main()
{
    int choice;

    printf("========================================\n");
    printf("   School Management System - Day 30    \n");
    printf("   Admission No: 25CSAIM290             \n");
    printf("========================================\n");

    do
{
        printf("\n===== MAIN MENU =====\n");
        printf("1.  Add Student\n");
        printf("2.  View All Students\n");
        printf("3.  View Marksheet\n");
        printf("4.  Show Topper\n");
        printf("5.  Class Statistics\n");
        printf("6.  Update Student Marks\n");
        printf("7.  Delete Student Record\n");
        printf("8.  Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
{
            case 1: addStudent(); break;
            case 2: viewAllStudents(); break;
            case 3: viewMarksheet(); break;
            case 4: showToppers(); break;
            case 5: classStatistics(); break;
            case 6: updateMarks(); break;
            case 7: deleteStudent(); break;
            case 8: printf("\nThank you! Exiting School Management System.\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 8);

    return 0;
}
