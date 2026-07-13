#include <stdio.h>

int main() 
{
    char str[200];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    int len = 0;
    while (str[len] != '\0' && str[len] != '\n') len++;
    str[len] = '\0';

    printf("Compressed string: ");

    int i = 0;
    while (i < len) 
    {
        int count = 1;
        while (i + count < len && str[i + count] == str[i]) 
        {
            count++;
        }
        printf("%c%d", str[i], count);
        i += count;
    }
    printf("\n");

    return 0;
}
