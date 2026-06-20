#include <stdio.h>
#include <math.h>

int isArmstrong(int n) 
{
    int sum = 0, digits = 0, digit, temp = n;

    while (temp != 0) 
    {
        digits++;
        temp /= 10;
    }

    temp = n;
    while (temp != 0) 
    {
        digit = temp % 10;
        sum += (int)pow(digit, digits);
        temp /= 10;
    }

    return (sum == n);
}

int main() 
{
    int n;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (isArmstrong(n)) 
    {
        printf("%d is an Armstrong number.\n", n);
    } 
    else 
    {
        printf("%d is NOT an Armstrong number.\n", n);
    }

    return 0;
}
