

#include <stdio.h>
#include <math.h>

int main()
{
    int choice;
    double a, b, result;

    do
    {
        printf("\n===== Menu-Driven Calculator =====\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus (integers)\n");
        printf("6. Power (a^b)\n");
        printf("7. Square Root\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 6)
        {
            if (choice == 7)
            {
                printf("Enter a number: ");
                scanf("%lf", &a);
            } 
            else
            {
                printf("Enter first number: ");
                scanf("%lf", &a);
                if (choice != 7)
                {
                    printf("Enter second number: ");
                    scanf("%lf", &b);
                }
            }
        }

        switch (choice)
        {
            case 1:
                result = a + b;
                printf("%.4lf + %.4lf = %.4lf\n", a, b, result);
                break;
            case 2:
                result = a - b;
                printf("%.4lf - %.4lf = %.4lf\n", a, b, result);
                break;
            case 3:
                result = a * b;
                printf("%.4lf * %.4lf = %.4lf\n", a, b, result);
                break;
            case 4:
                if (b == 0) printf("Error: Division by zero!\n");
                else
                { 
                    result = a / b; printf("%.4lf / %.4lf = %.4lf\n", a, b, result); 
                }
                break;
            case 5:
                if ((int)b == 0) printf("Error: Modulus by zero!\n");
                else printf("%d %% %d = %d\n", (int)a, (int)b, (int)a % (int)b);
                break;
            case 6:
                result = pow(a, b);
                printf("%.4lf ^ %.4lf = %.4lf\n", a, b, result);
                break;
            case 7:
                printf("Enter a number: ");
                scanf("%lf", &a);
                if (a < 0) printf("Error: Cannot take square root of negative number!\n");
                else printf("sqrt(%.4lf) = %.4lf\n", a, sqrt(a));
                break;
            case 8:
                printf("Exiting Calculator. Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 8);

    return 0;
}
