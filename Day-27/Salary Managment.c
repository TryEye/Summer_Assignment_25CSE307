#include <stdio.h>

#define MAX_EMP 50

struct SalaryRecord 
{
    int    empId;
    char   name[100];
    double basicSalary;
    double hra;          
    double da;           
    double deductions;
    double netSalary;
};

int main()
{
    struct SalaryRecord records[MAX_EMP];
    int n;

    printf("===== Salary Management System =====\n");
    printf("Enter number of employees: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++)
    {
        printf("\n--- Employee %d ---\n", i + 1);
        printf("Enter ID: ");
        scanf("%d", &records[i].empId);
        getchar();
        printf("Enter Name: ");
        fgets(records[i].name, 100, stdin);
        int len = 0;
        while (records[i].name[len] != '\0' && records[i].name[len] != '\n') len++;
        records[i].name[len] = '\0';
        printf("Enter Basic Salary: Rs. ");
        scanf("%lf", &records[i].basicSalary);

        
        records[i].hra        = 0.20 * records[i].basicSalary;
        records[i].da         = 0.10 * records[i].basicSalary;
        records[i].deductions = 0.05 * records[i].basicSalary; 
        records[i].netSalary  = records[i].basicSalary + records[i].hra
                              + records[i].da - records[i].deductions;
        getchar();
    }

    printf("\n====== SALARY SLIP SUMMARY ======\n");
    printf("%-5s %-20s %-12s %-10s %-10s %-12s %-12s\n",
           "ID", "Name", "Basic", "HRA(20%)", "DA(10%)", "Deduct(5%)", "Net Salary");
    printf("-------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        printf("%-5d %-20s %-12.2lf %-10.2lf %-10.2lf %-12.2lf %-12.2lf\n",
               records[i].empId, records[i].name, records[i].basicSalary,
               records[i].hra, records[i].da, records[i].deductions, records[i].netSalary);
    }

    return 0;
}
