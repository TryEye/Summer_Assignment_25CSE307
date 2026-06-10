#include <stdio.h>

int main() 
{
    int n, reversed = 0, digit;

    printf("Enter an integer: ");
    scanf("%d", &n);

    int original = n;
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

    if (original == reversed) 
    {
        printf("%d is a Palindrome number.\n", original);
    } else {
        printf("%d is NOT a Palindrome number.\n", original);
    }

    return 0;
}
