#include <stdio.h>

int main() 
{
    int rows, cols;

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int mat[rows][cols];

    printf("Enter elements of matrix:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &mat[i][j]);

    printf("Row-wise sums:\n");
    for (int i = 0; i < rows; i++) 
    {
        int rowSum = 0;
        for (int j = 0; j < cols; j++) 
        {
            rowSum += mat[i][j];
        }
        printf("Row %d sum = %d\n", i + 1, rowSum);
    }

    return 0;
}
