#include <stdio.h>

int main() 
{
    int rows;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("\nRepeated Character Pattern:\n");
    for (int i = 1; i <= rows; i++) 
    {
        for (int j = 1; j <= i; j++) 
        {
            printf("%c", 'A' + i - 1);
        }
        printf("\n");
    }

    return 0;
}
