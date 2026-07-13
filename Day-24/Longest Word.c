#include <stdio.h>

int main() 
{
    char str[500];
    char longestWord[200] = "", currentWord[200] = "";
    int maxLen = 0, currentLen = 0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    int i = 0;
    while (str[i] != '\0' && str[i] != '\n') 
    {
        if (str[i] != ' ' && str[i] != '\t') 
        {
            currentWord[currentLen++] = str[i];
        } 
        else 
        {
            currentWord[currentLen] = '\0';
            if (currentLen > maxLen) 
            {
                maxLen = currentLen;
                int k;
                for (k = 0; k < currentLen; k++) 
                {
                    longestWord[k] = currentWord[k];
                }
                longestWord[k] = '\0';
            }
            currentLen = 0;
        }
        i++;
    }

    currentWord[currentLen] = '\0';
    if (currentLen > maxLen) 
    {
        int k;
        for (k = 0; k < currentLen; k++) 
        {
            longestWord[k] = currentWord[k];
        }
        longestWord[k] = '\0';
    }

    printf("Longest word: \"%s\" (length = %d)\n", longestWord, maxLen > currentLen ? maxLen : currentLen);

    return 0;
}
