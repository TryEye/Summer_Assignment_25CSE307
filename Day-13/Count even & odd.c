#include <stdio.h>

int main() 
{
    int n, evenCount = 0, oddCount = 0;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
        if (arr[i] % 2 == 0) 
        {
            evenCount++;
        } 
        else 
        {
            oddCount++;
        }
    }

    printf("Even elements count = %d\n", evenCount);
    printf("Odd  elements count = %d\n", oddCount);

    return 0;
}
