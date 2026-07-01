#include <stdio.h>

int main() 
{
    char str[200];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    int len = 0;
    while (str[len] != '\0' && str[len] != '\n') len++;
    str[len] = '\0';

    int left = 0, right = len - 1, isPalin = 1;
    while (left < right) 
    {
        if (str[left] != str[right]) 
        {
            isPalin = 0;
            break;
        }
        left++;
        right--;
    }

    if (isPalin) 
    {
        printf("\"%s\" is a Palindrome string.\n", str);
    } 
    else 
    {
        printf("\"%s\" is NOT a Palindrome string.\n", str);
    }

    return 0;
}
