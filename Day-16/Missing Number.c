#include <stdio.h>

int main() 
{
    int n;

    printf("Enter value of N (array contains 1 to N with one missing): ");
    scanf("%d", &n);

    int arr[n - 1];

    printf("Enter %d elements:\n", n - 1);
    for (int i = 0; i < n - 1; i++) 
    {
        scanf("%d", &arr[i]);
    }

    int expectedSum = n * (n + 1) / 2;
    int actualSum   = 0;

    for (int i = 0; i < n - 1; i++) 
    {
        actualSum += arr[i];
    }

    printf("Missing number = %d\n", expectedSum - actualSum);

    return 0;
}
