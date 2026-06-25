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

    int unique[n], uCount = 0;

    for (int i = 0; i < n; i++) 
    {
        int isDuplicate = 0;
        for (int j = 0; j < uCount; j++) 
        {
            if (arr[i] == unique[j]) 
            {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) 
        {
            unique[uCount++] = arr[i];
        }
    }

    printf("Array after removing duplicates: ");
    for (int i = 0; i < uCount; i++) 
    {
        printf("%d ", unique[i]);
    }
    printf("\n");

    return 0;
}
