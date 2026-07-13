

#include <stdio.h>
#include <string.h>

int main()
{
    char name[100];
    int age;
    char citizenStatus[10];

    printf("===================================\n");
    printf("     Voting Eligibility System     \n");
    printf("===================================\n");

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    
    int len = 0;
    while (name[len] != '\0' && name[len] != '\n') len++;
    name[len] = '\0';

    printf("Enter your age: ");
    scanf("%d", &age);
    getchar();

    printf("Are you a citizen of India? (yes/no): ");
    fgets(citizenStatus, sizeof(citizenStatus), stdin);

    int isCitizen = (citizenStatus[0] == 'y' || citizenStatus[0] == 'Y');

    printf("\n--- Eligibility Report for %s ---\n", name);
    printf("Age     : %d\n", age);
    printf("Citizen : %s\n", isCitizen ? "Yes" : "No");

    if (age >= 18 && isCitizen)
    {
        printf("Status  : ELIGIBLE to vote.\n");
    } 
    else if (!isCitizen)
    {
        printf("Status  : NOT eligible (not a citizen).\n");
    } 
    else
    {
        printf("Status  : NOT eligible (age below 18, need %d more year(s)).\n", 18 - age);
    }

    return 0;
}
