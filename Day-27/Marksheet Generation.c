#include <stdio.h>

int main()
{
    char name[100];
    int rollNo;
    float marks[5];
    char subjects[5][30] = {"Mathematics", "Physics", "Chemistry", "English", "Computer Science"};
    float total = 0, percentage;
    char grade;

    printf("===================================\n");
    printf("     Marksheet Generation System   \n");
    printf("===================================\n");

    printf("Enter Student Name: ");
    fgets(name, sizeof(name), stdin);
    int len = 0;
    while (name[len] != '\0' && name[len] != '\n') len++;
    name[len] = '\0';

    printf("Enter Roll Number: ");
    scanf("%d", &rollNo);

    printf("\nEnter marks (out of 100) for each subject:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%-20s: ", subjects[i]);
        scanf("%f", &marks[i]);
        total += marks[i];
    }

    percentage = total / 5.0f;

    if (percentage >= 90)  grade = 'A';
    else if (percentage >= 75) grade = 'B';
    else if (percentage >= 60) grade = 'C';
    else if (percentage >= 45) grade = 'D';
    else   grade = 'F';

    
    printf("\n========================================\n");
    printf("            MARKSHEET                   \n");
    printf("========================================\n");
    printf("Name        : %s\n", name);
    printf("Roll Number : %d\n", rollNo);
    printf("----------------------------------------\n");
    printf("%-20s  %s\n", "Subject", "Marks");
    printf("----------------------------------------\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%-20s  %.1f / 100\n", subjects[i], marks[i]);
    }
    printf("----------------------------------------\n");
    printf("Total Marks : %.1f / 500\n", total);
    printf("Percentage  : %.2f%%\n", percentage);
    printf("Grade       : %c\n", grade);
    printf("Result      : %s\n", (grade != 'F') ? "PASS" : "FAIL");
    printf("========================================\n");

    return 0;
}
