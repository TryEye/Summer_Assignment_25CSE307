#include <stdio.h>
#include <string.h>

int main()
{
    int n;

    printf("Enter number of words: ");
    scanf("%d", &n);
    getchar();

    char words[n][100];

    printf("Enter %d words:\n", n);
    for (int i = 0; i < n; i++)
    {
        fgets(words[i], 100, stdin);
        int len = 0;
        while (words[i][len] != '\0' && words[i][len] != '\n') len++;
        words[i][len] = '\0';
    }

    
    char temp[100];
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (strlen(words[j]) < strlen(words[minIdx]))
            {
                minIdx = j;
            }
        }
        if (minIdx != i)
       {
            strcpy(temp, words[i]);
            strcpy(words[i], words[minIdx]);
            strcpy(words[minIdx], temp);
        }
    }

    printf("Words sorted by length:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s (length = %d)\n", words[i], (int)strlen(words[i]));
    }

    return 0;
}
