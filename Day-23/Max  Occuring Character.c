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

    int maxFreq = 0;
    char maxChar = str[0];

    for (int i = 0; i < 256; i++) 
    {
        if (freq[i] > maxFreq) 
        {
            maxFreq = freq[i];
            maxChar = (char)i;
        }
    }

    printf("Maximum occurring character: '%c' (frequency = %d)\n", maxChar, maxFreq);

    return 0;
}
