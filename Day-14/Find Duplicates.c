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

    printf("Duplicate elements: ");
    int foundDuplicate = 0;

    for (int i = 0; i < n - 1; i++) 
            
    {
        for (int j = i + 1; j < n; j++) 
                
        {
            if (arr[i] == arr[j]) 
            {
                int alreadyPrinted = 0;
                for (int k = 0; k < i; k++) 
                {
                    if (arr[k] == arr[i]) 
                    {
                        alreadyPrinted = 1;
                        break;
                    }
                }
                if (!alreadyPrinted) 
                {
                    printf("%d ", arr[i]);
                    foundDuplicate = 1;
                }
                break;
            }
        }
    }

    if (!foundDuplicate) 
    {
        printf("None");
    }
    printf("\n");

    return 0;
}
