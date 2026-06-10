#include <stdio.h>

int main() 
{
    int n, reversed = 0, digit;

    printf("Enter an integer: ");
    scanf("%d", &n);

    int temp = n;
    if (temp < 0) 
    {
        temp = -temp;
    }

    while (temp != 0) 
    {
        digit = temp % 10;
        reversed = reversed * 10 + digit;
        temp /= 10;
    }

    if (n < 0) 
    {
        reversed = -reversed;
    }

    printf("Reversed number of %d = %d\n", n, reversed);

    return 0;
}
