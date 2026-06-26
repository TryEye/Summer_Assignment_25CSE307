#include <stdio.h>

int main() 
{
    int n, target;

    printf("Enter size of sorted array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements in ascending order:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &target);

    int low = 0, high = n - 1, mid, result = -1;

    while (low <= high) 
    {
        mid = low + (high - low) / 2;

        if (arr[mid] == target) 
        {
            result = mid;
            break;
        } 
        else if (arr[mid] < target) 
        {
            low = mid + 1;
        } 
        else 
        {
            high = mid - 1;
        }
    }

    if (result != -1) 
    {
        printf("Element %d found at index %d.\n", target, result);
    } 
    else 
    {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}
