#include <stdio.h>

int main() 
{
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nArray elements:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    return 0;
}
