#include <stdio.h>
#include <limits.h>

int main() 
{
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    if (n < 2) 
    {
        printf("Array must have at least 2 elements.\n");
        return 1;
    }

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    int largest = INT_MIN, secondLargest = INT_MIN;

    for (int i = 0; i < n; i++) 
    {
        if (arr[i] > largest) 
        {
            secondLargest = largest;
            largest = arr[i];
        } 
        else if (arr[i] > secondLargest && arr[i] != largest) 
        {
            secondLargest = arr[i];
        }
    }

    if (secondLargest == INT_MIN) 
    {
        printf("No second largest element (all elements are equal).\n");
    } 
    else 
    {
        printf("Second largest element = %d\n", secondLargest);
    }

    return 0;
}
