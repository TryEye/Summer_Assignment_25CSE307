#include <stdio.h>

int main() 
{
    int rows, cols;

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int A[rows][cols], T[cols][rows];

    printf("Enter elements of matrix:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &A[i][j]);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            T[j][i] = A[i][j];

    printf("Original matrix:\n");
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++)
            printf("%4d", A[i][j]);
        printf("\n");
    }

    printf("Transposed matrix:\n");
    for (int i = 0; i < cols; i++) 
    {
        for (int j = 0; j < rows; j++)
            printf("%4d", T[i][j]);
        printf("\n");
    }

    return 0;
}
