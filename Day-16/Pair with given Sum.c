#include <stdio.h>

int main() 
{
    int n, targetSum;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter target sum: ");
    scanf("%d", &targetSum);

    int found = 0;
    printf("Pairs with sum %d:\n", targetSum);

    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[i] + arr[j] == targetSum) 
            {
                printf("(%d, %d)\n", arr[i], arr[j]);
                found = 1;
            }
        }
    }

    if (!found) 
    {
        printf("No pair found with sum %d.\n", targetSum);
    }

    return 0;
}
