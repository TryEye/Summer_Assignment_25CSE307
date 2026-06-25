#include <stdio.h>

int main() 
{
    int n, k;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter number of positions to rotate left: ");
    scanf("%d", &k);

    k = k % n;

    int temp[k];
    for (int i = 0; i < k; i++) 
    {
        temp[i] = arr[i];
    }

    for (int i = 0; i < n - k; i++) 
    {
        arr[i] = arr[i + k];
    }

    for (int i = 0; i < k; i++) 
    {
        arr[n - k + i] = temp[i];
    }

    printf("Array after left rotation by %d: ", k);
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
