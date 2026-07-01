#include <stdio.h>

int main() 
{
    char str[200], result[200];
    int j = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) 
    {
        if (str[i] != ' ') 
        {
            result[j++] = str[i];
        }
    }
    result[j] = '\0';

    printf("String after removing spaces: %s\n", result);

    return 0;
}
