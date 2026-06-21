#include <stdio.h>

int main() 
{
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    int sum = 0;

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    double average = (double)sum / n;

    printf("Sum     = %d\n", sum);
    printf("Average = %.2lf\n", average);

    return 0;
}
