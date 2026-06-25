#include <stdio.h>

int alreadyExists(int arr[], int size, int val) 
{
    for (int i = 0; i < size; i++) 
    {
        if (arr[i] == val) return 1;
    }
    return 0;
}

int main() 
{
    int m, n;

    printf("Enter size of first array: ");
    scanf("%d", &m);
    int arr1[m];
    printf("Enter %d elements:\n", m);
    for (int i = 0; i < m; i++) scanf("%d", &arr1[i]);

    printf("Enter size of second array: ");
    scanf("%d", &n);
    int arr2[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr2[i]);

    int unionArr[m + n], uSize = 0;

    for (int i = 0; i < m; i++) 
    {
        if (!alreadyExists(unionArr, uSize, arr1[i])) 
        {
            unionArr[uSize++] = arr1[i];
        }
    }
    for (int i = 0; i < n; i++) 
    {
        if (!alreadyExists(unionArr, uSize, arr2[i])) 
        {
            unionArr[uSize++] = arr2[i];
        }
    }

    printf("Union of arrays: ");
    for (int i = 0; i < uSize; i++) 
    {
        printf("%d ", unionArr[i]);
    }
    printf("\n");

    return 0;
}
