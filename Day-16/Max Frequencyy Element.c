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
        scanf("%d", &arr[i]);
    }

    int maxFreq    = 0;
    int maxElement = arr[0];

    for (int i = 0; i < n; i++) 
    {
        int count = 0;
        for (int j = 0; j < n; j++) 
        {
            if (arr[j] == arr[i]) 
            {
                count++;
            }
        }
        if (count > maxFreq) 
        {
            maxFreq    = count;
            maxElement = arr[i];
        }
    }

    printf("Element with maximum frequency: %d (appears %d times)\n", maxElement, maxFreq);

    return 0;
}
