#include <stdio.h>

int main() 
{
    char str1[200], str2[200];
    int freq[256] = {0};

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);

    int len1 = 0, len2 = 0;
    while (str1[len1] != '\0' && str1[len1] != '\n') len1++;
    str1[len1] = '\0';
    while (str2[len2] != '\0' && str2[len2] != '\n') len2++;
    str2[len2] = '\0';

    if (len1 != len2) 
    {
        printf("The strings are NOT anagrams.\n");
        return 0;
    }

    for (int i = 0; i < len1; i++) 
    {
        freq[(unsigned char)str1[i]]++;
    }
    for (int i = 0; i < len2; i++) 
    {
        freq[(unsigned char)str2[i]]--;
    }

    int isAnagram = 1;
    for (int i = 0; i < 256; i++) 
    {
        if (freq[i] != 0) 
        {
            isAnagram = 0;
            break;
        }
    }

    if (isAnagram) 
    {
        printf("\"%s\" and \"%s\" are Anagrams.\n", str1, str2);
    } 
    else 
    {
        printf("\"%s\" and \"%s\" are NOT Anagrams.\n", str1, str2);
    }

    return 0;
}
