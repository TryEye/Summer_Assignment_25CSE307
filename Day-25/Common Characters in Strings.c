#include <stdio.h>

int main() 
{
    char str1[200], str2[200];
    int freq1[256] = {0}, freq2[256] = {0};

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);

    for (int i = 0; str1[i] != '\0' && str1[i] != '\n'; i++)
        freq1[(unsigned char)str1[i]]++;
    for (int i = 0; str2[i] != '\0' && str2[i] != '\n'; i++)
        freq2[(unsigned char)str2[i]]++;

    printf("Common characters: ");
    int found = 0;
    for (int i = 0; i < 256; i++) 
    {
        if (freq1[i] > 0 && freq2[i] > 0 && i != '\n') 
        {
            printf("'%c' ", (char)i);
            found = 1;
        }
    }
    if (!found) printf("None");
    printf("\n");

    return 0;
}
