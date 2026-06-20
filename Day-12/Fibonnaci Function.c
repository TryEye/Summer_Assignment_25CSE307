#include <stdio.h>

void printFibonacci(int n) 
{
    long long a = 0, b = 1, next;
    printf("Fibonacci Series: ");
    for (int i = 1; i <= n; i++) 
    {
        printf("%lld ", a);
        next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    printFibonacci(n);

    return 0;
}
