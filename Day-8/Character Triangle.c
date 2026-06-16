#include <stdio.h>

int main() 
{
    int rows;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("\nCharacter Triangle:\n");
    for (int i = 1; i <= rows; i++) 
    {
        for (int j = 0; j < i; j++) 
        {
            printf("%c", 'A' + j);
        }
        printf("\n");
    }

    return 0;
}
