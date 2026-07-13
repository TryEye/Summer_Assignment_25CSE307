#include <stdio.h>
#include <string.h>

char str[500];

void inputString() 
{
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    int len = 0;
    while (str[len] != '\0' && str[len] != '\n') len++;
    str[len] = '\0';
}

void findLength() 
{
    int len = 0;
    while (str[len] != '\0') len++;
    printf("Length = %d\n", len);
}

void reverseStr() 
{
    int len = strlen(str);
    char rev[500];
    for (int i = 0; i < len; i++) rev[i] = str[len - 1 - i];
    rev[len] = '\0';
    printf("Reversed: %s\n", rev);
}

void checkPalinStr() 
{
    int len = strlen(str), ok = 1;
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - 1 - i])
        { ok = 0; break; }
    }
    printf("%s is %s palindrome.\n", str, ok ? "a" : "NOT a");
}

void countVowCon() 
{
    int v = 0, c = 0;
    for (int i = 0; str[i]; i++)
    {
        char ch = str[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            char lc = (ch >= 'A' && ch <= 'Z') ? ch + 32 : ch;
            if (lc == 'a' || lc == 'e' || lc == 'i' || lc == 'o' || lc == 'u') v++;
            else c++;
        }
    }
    printf("Vowels = %d, Consonants = %d\n", v, c);
}

void toUppercase() 
{
    printf("Uppercase: ");
    for (int i = 0; str[i]; i++)
    {
        char c = str[i];
        if (c >= 'a' && c <= 'z') c -= 32;
        printf("%c", c);
    }
    printf("\n");
}

void countWords() 
{
    int words = 0, inWord = 0;
    for (int i = 0; str[i]; i++)
    {
        if (str[i] != ' ')

        { if (!inWord)

            { words++; inWord = 1; } 
        
        }
        else inWord = 0;
    }
    printf("Word count = %d\n", words);
}

int main()
{
    int choice;
    do
    {
        printf("\n===== String Operations Menu =====\n");
        printf("1. Input String\n");
        printf("2. Find Length\n");
        printf("3. Reverse String\n");
        printf("4. Check Palindrome\n");
        printf("5. Count Vowels & Consonants\n");
        printf("6. Convert to Uppercase\n");
        printf("7. Count Words\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1: inputString(); break;
            case 2: findLength(); break;
            case 3: reverseStr(); break;
            case 4: checkPalinStr(); break;
            case 5: countVowCon(); break;
            case 6: toUppercase(); break;
            case 7: countWords(); break;
            case 8: printf("Exiting String Operations.\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 8);

    return 0;
}
