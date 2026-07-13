#include <stdio.h>
#include <string.h>

int main() 
{
    char str1[200], str2[200], combined[400];

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
        printf("The strings are NOT rotations of each other.\n");
        return 0;
    }

    strcpy(combined, str1);
    strcat(combined, str1);

    if (strstr(combined, str2) != NULL) 
    {
        printf("\"%s\" IS a rotation of \"%s\".\n", str2, str1);
    } 
    else 
    {
        printf("\"%s\" is NOT a rotation of \"%s\".\n", str2, str1);
    }

    return 0;
}
