#include <stdio.h>

int main() 
{
    int n, target, found = 0;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &target);

    for (int i = 0; i < n; i++) 
    {
        if (arr[i] == target) 
        {
            printf("Element %d found at index %d.\n", target, i);
            found = 1;
        }
    }

    if (!found) 
    {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}
