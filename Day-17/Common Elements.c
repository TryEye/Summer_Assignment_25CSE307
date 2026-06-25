#include <stdio.h>

int contains(int arr[], int size, int val) 
{
    for (int i = 0; i < size; i++) 
    {
        if (arr[i] == val) return 1;
    }
    return 0;
}

int main() 
{
    int m, n, p;

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

    printf("Enter size of third array: ");
    scanf("%d", &p);
    int arr3[p];
    printf("Enter %d elements:\n", p);
    for (int i = 0; i < p; i++) scanf("%d", &arr3[i]);

    int common[m], cSize = 0;

    for (int i = 0; i < m; i++) 
    {
        if (contains(arr2, n, arr1[i]) && contains(arr3, p, arr1[i])
        && !contains(common, cSize, arr1[i])) 
        {
            common[cSize++] = arr1[i];
        }
    }

    printf("Common elements: ");
    if (cSize == 0) 
    {
        printf("None");
    } 
    else 
    {
        for (int i = 0; i < cSize; i++) 
        {
            printf("%d ", common[i]);
        }
    }
    printf("\n");

    return 0;
}
