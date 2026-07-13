#include <stdio.h>

int main()
{
    int correctPin = 1234;
    int enteredPin;
    double balance  = 15000.00;
    int choice;
    int attempts    = 0;

    printf("================================\n");
    printf("      Welcome to ATM System     \n");
    printf("================================\n");

    
    while (attempts < 3)
    {
        printf("Enter your 4-digit PIN: ");
        scanf("%d", &enteredPin);
        attempts++;

        if (enteredPin == correctPin)
        {
            printf("PIN verified successfully!\n\n");
            break;
        } 
        else
        {
            printf("Incorrect PIN. Attempts remaining: %d\n", 3 - attempts);
        }

        if (attempts == 3)
        {
            printf("Card blocked due to 3 failed attempts. Contact bank.\n");
            return 0;
        }
    }

    do
    {
        printf("\n====== ATM MENU ======\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Current Balance: Rs. %.2lf\n", balance);

        } 
        else if (choice == 2)
        {
            double amount;
            printf("Enter amount to deposit: Rs. ");
            scanf("%lf", &amount);
            if (amount > 0)
            {
                balance += amount;
                printf("Rs. %.2lf deposited. New balance: Rs. %.2lf\n", amount, balance);
            } 
            else
            {
                printf("Invalid amount.\n");
            }

        } 
        else if (choice == 3)
        {
            double amount;
            printf("Enter amount to withdraw: Rs. ");
            scanf("%lf", &amount);
            if (amount <= 0)
            {
                printf("Invalid amount.\n");
            } 
            else if (amount > balance)
            {
                printf("Insufficient balance!\n");
            } 
            else
            {
                balance -= amount;
                printf("Rs. %.2lf withdrawn. Remaining balance: Rs. %.2lf\n", amount, balance);
            }

        } 
        else if (choice == 4)
        {
            printf("Thank you for using our ATM. Goodbye!\n");
        } 
        else
        {
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}
