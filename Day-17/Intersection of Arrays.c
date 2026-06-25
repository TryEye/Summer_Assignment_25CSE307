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

    int intersect[m], iSize = 0;

    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (arr1[i] == arr2[j] && !alreadyExists(intersect, iSize, arr1[i])) 
            {
                intersect[iSize++] = arr1[i];
                break;
            }
        }
    }

    printf("Intersection of arrays: ");
    if (iSize == 0) 
    {
        printf("None");
    } 
    else 
    {
        for (int i = 0; i < iSize; i++) 
        {
            printf("%d ", intersect[i]);
        }
    }
    printf("\n");

    return 0;
}
