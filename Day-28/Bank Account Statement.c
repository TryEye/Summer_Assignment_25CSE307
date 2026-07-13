#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 20

struct BankAccount 
{
    int    accNo;
    char   holderName[100];
    double balance;
};

int findAccount(struct BankAccount accounts[], int count, int accNo) 
{
    for (int i = 0; i < count; i++)
    {
        if (accounts[i].accNo == accNo) return i;
    }
    return -1;
}

int main()
{
    struct BankAccount accounts[MAX_ACCOUNTS];
    int count = 0, choice;

    do
    {
        printf("\n===== Bank Account System =====\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1)
        {
            if (count >= MAX_ACCOUNTS)
            { 
                printf("Account limit reached!\n"); 
            }
            else
            {
                printf("Enter Account Number: ");
                scanf("%d", &accounts[count].accNo);
                getchar();
                printf("Enter Holder Name: ");
                fgets(accounts[count].holderName, 100, stdin);
                int len = 0;
                while (accounts[count].holderName[len] != '\0' && accounts[count].holderName[len] != '\n') len++;
                accounts[count].holderName[len] = '\0';
                printf("Enter Initial Deposit: Rs. ");
                scanf("%lf", &accounts[count].balance);
                getchar();
                count++;
                printf("Account created successfully!\n");
            }

        } 
        else if (choice == 2 || choice == 3 || choice == 4)
        {
            int accNo;
            printf("Enter Account Number: ");
            scanf("%d", &accNo);
            getchar();
            int idx = findAccount(accounts, count, accNo);
            if (idx == -1)
            { 
                printf("Account not found!\n"); 
            }
            else
            {
                if (choice == 2)
                {
                    double amt;
                    printf("Enter deposit amount: Rs. ");
                    scanf("%lf", &amt);
                    getchar();
                    if (amt > 0)
                    { 
                        accounts[idx].balance += amt; printf("Deposited Rs. %.2lf. Balance: Rs. %.2lf\n", amt, accounts[idx].balance); 
                    }
                    else printf("Invalid amount.\n");
                } 
                else if (choice == 3)
                {
                    double amt;
                    printf("Enter withdrawal amount: Rs. ");
                    scanf("%lf", &amt);
                    getchar();
                    if (amt <= 0) printf("Invalid amount.\n");
                    else if (amt > accounts[idx].balance) printf("Insufficient balance!\n");
                    else
                    { 
                        accounts[idx].balance -= amt; printf("Withdrawn Rs. %.2lf. Balance: Rs. %.2lf\n", amt, accounts[idx].balance); 
                    }
                } 
                else
                {
                    printf("Account: %s | Balance: Rs. %.2lf\n", accounts[idx].holderName, accounts[idx].balance);
                }
            }

        } 
        else if (choice == 5)
        {
            if (count == 0) printf("No accounts.\n");
            else
            {
                printf("\n%-10s %-25s %-15s\n", "Acc No", "Holder Name", "Balance");
                printf("--------------------------------------------------\n");
                for (int i = 0; i < count; i++)
                {
                    printf("%-10d %-25s Rs. %.2lf\n", accounts[i].accNo, accounts[i].holderName, accounts[i].balance);
                }
            }

        } 
        else if (choice == 6)
        {
            printf("Exiting Bank Account System.\n");
        } 
        else
        {
            printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}
