#include <stdio.h>

int main() 
{
    char str[200];
    int freq[256] = {0};

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) 
    {
        freq[(unsigned char)str[i]]++;
    }

    printf("Character frequencies:\n");
    for (int i = 0; i < 256; i++) 
    {
        if (freq[i] > 0) 
        {
            printf("'%c' : %d\n", (char)i, freq[i]);
        }
    }

    return 0;
}
