#include <stdio.h>

int isPalindrome(int n) 
{
    int original = n, reversed = 0, digit;
    if (n < 0) n = -n;
    int temp = n;
    while (temp != 0) 
    {
        digit = temp % 10;
        reversed = reversed * 10 + digit;
        temp /= 10;
    }
    return (original == reversed);
}

int main() 
{
    int n;

    printf("Enter an integer: ");
    scanf("%d", &n);

    if (isPalindrome(n)) 
    {
        printf("%d is a Palindrome number.\n", n);
    } 
    else 
    {
        printf("%d is NOT a Palindrome number.\n", n);
    }

    return 0;
}
