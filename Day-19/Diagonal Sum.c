#include <stdio.h>

int main() 
{
    int n;

    printf("Enter order of square matrix: ");
    scanf("%d", &n);

    int mat[n][n];

    printf("Enter elements of matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    int primarySum   = 0;
    int secondarySum = 0;

    for (int i = 0; i < n; i++) 
    {
        primarySum   += mat[i][i];
        secondarySum += mat[i][n - 1 - i];
    }

    int totalDiagonalSum = primarySum + secondarySum;
    if (n % 2 != 0) 
    {
        totalDiagonalSum -= mat[n / 2][n / 2];
    }

    printf("Primary diagonal sum   = %d\n", primarySum);
    printf("Secondary diagonal sum = %d\n", secondarySum);
    printf("Total diagonal sum     = %d\n", totalDiagonalSum);

    return 0;
}
