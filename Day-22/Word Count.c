#include <stdio.h>

int main() {
    char str[500];
    int wordCount = 0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    int inWord = 0;
    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) 
    {
        if (str[i] != ' ' && str[i] != '\t') 
        {
            if (!inWord) 
            {
                wordCount++;
                inWord = 1;
            }
        } 
        else 
        {
            inWord = 0;
        }
    }

    printf("Number of words = %d\n", wordCount);

    return 0;
}
