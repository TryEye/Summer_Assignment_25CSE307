#include <stdio.h>
#include <string.h>

int main() 
{
    char str[200];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    int len = 0;
    while (str[len] != '\0' && str[len] != '\n') len++;
    str[len] = '\0';

    int left = 0, right = len - 1;
    char temp;
    while (left < right) 
    {
        temp        = str[left];
        str[left]   = str[right];
        str[right]  = temp;
        left++;
        right--;
    }

    printf("Reversed string: %s\n", str);

    return 0;
}
