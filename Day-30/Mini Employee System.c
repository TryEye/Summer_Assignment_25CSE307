#include <stdio.h>
#include <string.h>

#define MAX 50

int    empIds[MAX];
char   empNames[MAX][100];
char   empDepts[MAX][50];
double empSalaries[MAX];
int    empCount = 0;

void addEmployee() 
{
    if (empCount >= MAX)
    { 
        printf("Full!\n"); return; 
    }
    int i = empCount;
    printf("Enter Employee ID: ");
    scanf("%d", &empIds[i]);
    getchar();
    printf("Enter Name: ");
    fgets(empNames[i], 100, stdin);
    int len = 0;
    while (empNames[i][len] != '\0' && empNames[i][len] != '\n') len++;
    empNames[i][len] = '\0';
    printf("Enter Department: ");
    fgets(empDepts[i], 50, stdin);
    len = 0;
    while (empDepts[i][len] != '\0' && empDepts[i][len] != '\n') len++;
    empDepts[i][len] = '\0';
    printf("Enter Salary: Rs. ");
    scanf("%lf", &empSalaries[i]);
    getchar();
    empCount++;
    printf("Employee added!\n");
}

void displayAll() 
{
    if (empCount == 0)
    { 
        printf("No records.\n"); return; 
    }
    printf("\n%-6s %-22s %-15s %-12s\n", "ID", "Name", "Department", "Salary");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < empCount; i++)
    {
        printf("%-6d %-22s %-15s Rs. %.2lf\n", empIds[i], empNames[i], empDepts[i], empSalaries[i]);
    }
}

void searchEmployee() 
{
    int id; printf("Enter Employee ID: "); scanf("%d", &id); getchar();
    for (int i = 0; i < empCount; i++)

    {
        if (empIds[i] == id)
        {
            printf("Name: %s | Dept: %s | Salary: Rs. %.2lf\n", empNames[i], empDepts[i], empSalaries[i]);
            return;
        }
    }
    printf("Employee not found.\n");
}

void giveRaise() 
{
    int id; double percent;
    printf("Enter Employee ID: "); scanf("%d", &id); getchar();
    printf("Enter raise percentage: "); scanf("%lf", &percent); getchar();
    for (int i = 0; i < empCount; i++)

    {
        if (empIds[i] == id)

        {
            double raise = empSalaries[i] * percent / 100.0;
            empSalaries[i] += raise;
            printf("Salary updated. New salary: Rs. %.2lf\n", empSalaries[i]);
            return;
        }
    }
    printf("Employee not found.\n");
}

void highestSalary() 
{
    if (empCount == 0)

    { 
        printf("No records.\n"); return; 
    }
    int topIdx = 0;
    for (int i = 1; i < empCount; i++)

    {
        if (empSalaries[i] > empSalaries[topIdx]) topIdx = i;
    }
    printf("Highest Paid: %s | Dept: %s | Rs. %.2lf\n",
           empNames[topIdx], empDepts[topIdx], empSalaries[topIdx]);
}

int main()
{
    int choice;
    do

    {
        printf("\n===== Mini Employee Management =====\n");
        printf("1. Add Employee\n");
        printf("2. Display All\n");
        printf("3. Search by ID\n");
        printf("4. Give Raise\n");
        printf("5. Show Highest Paid\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)

        {
            case 1: addEmployee(); break;
            case 2: displayAll(); break;
            case 3: searchEmployee(); break;
            case 4: giveRaise(); break;
            case 5: highestSalary(); break;
            case 6: printf("Exiting Employee Management.\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}
