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

    printf("Column-wise sums:\n");
    for (int j = 0; j < cols; j++) 
    {
        int colSum = 0;
        for (int i = 0; i < rows; i++) 
        {
            colSum += mat[i][j];
        }
        printf("Column %d sum = %d\n", j + 1, colSum);
    }

    return 0;
}
