#include <stdio.h>
#include <string.h>

#define MAX_EMP 50

struct Employee 
{
    int  empId;
    char name[100];
    char department[50];
    double salary;
};

void showEmployee(struct Employee e) 
{
    printf("ID         : %d\n", e.empId);
    printf("Name       : %s\n", e.name);
    printf("Department : %s\n", e.department);
    printf("Salary     : Rs. %.2lf\n", e.salary);
}

int main()
{
    struct Employee emp[MAX_EMP];
    int count = 0, choice;

    do
    {
        printf("\n===== Employee Management System =====\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1)
        {
            if (count >= MAX_EMP)
            {
                printf("Storage full!\n");
            } 
            else
            {
                printf("Enter Employee ID: ");
                scanf("%d", &emp[count].empId);
                getchar();
                printf("Enter Name: ");
                fgets(emp[count].name, 100, stdin);
                int len = 0;
                while (emp[count].name[len] != '\0' && emp[count].name[len] != '\n') len++;
                emp[count].name[len] = '\0';
                printf("Enter Department: ");
                fgets(emp[count].department, 50, stdin);
                len = 0;
                while (emp[count].department[len] != '\0' && emp[count].department[len] != '\n') len++;
                emp[count].department[len] = '\0';
                printf("Enter Salary: ");
                scanf("%lf", &emp[count].salary);
                getchar();
                count++;
                printf("Employee added successfully!\n");
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
                    printf("\n--- Employee %d ---\n", i + 1);
                    showEmployee(emp[i]);
                }
            }

        } 
        else if (choice == 3)
        {
            int id;
            printf("Enter Employee ID to search: ");
            scanf("%d", &id);
            getchar();
            int found = 0;
            for (int i = 0; i < count; i++)
            {
                if (emp[i].empId == id)
                {
                    printf("\n--- Found ---\n");
                    showEmployee(emp[i]);
                    found = 1;
                    break;
                }
            }
            if (!found) printf("Employee ID %d not found.\n", id);

        } 
        else if (choice == 4)
        {
            printf("Exiting Employee Management System.\n");
        } 
        else
        {
            printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}
