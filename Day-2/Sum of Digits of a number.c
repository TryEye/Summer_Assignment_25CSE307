#include <stdio.h>

int main() 
{
    int n, sum = 0, digit;

    printf("Enter an integer: ");
    scanf("%d", &n);

    if (n < 0) 
    {
        n = -n;
    }

    int temp = n;
    while (temp != 0)
    {
        digit = temp % 10;
        sum += digit;
        temp /= 10;
    }

    printf("Sum of digits of %d = %d\n", n, sum);

    return 0;
}
