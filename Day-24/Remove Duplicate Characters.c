#include <stdio.h>

int main() 
{
    char str[200], result[200];
    int seen[256] = {0};
    int j = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) 
    {
        unsigned char c = str[i];
        if (!seen[c]) 
        {
            seen[c]      = 1;
            result[j++]  = str[i];
        }
    }
    result[j] = '\0';

    printf("String after removing duplicate characters: %s\n", result);

    return 0;
}
