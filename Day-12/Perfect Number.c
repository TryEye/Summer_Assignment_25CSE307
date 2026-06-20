#include <stdio.h>

int isPerfect(int n) 
{
    int divisorSum = 0;
    for (int i = 1; i < n; i++) 
    {
        if (n % i == 0) 
        {
            divisorSum += i;
        }
    }
    return (divisorSum == n);
}

int main() {
    int n;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (isPerfect(n)) 
    {
        printf("%d is a Perfect number.\n", n);
    } 
    else 
    {
        printf("%d is NOT a Perfect number.\n", n);
    }

    return 0;
}
