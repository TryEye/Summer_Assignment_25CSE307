#include <stdio.h>

void reverseHelper(int n, int *result, int *multiplier) 
{
    if (n == 0) return;
    *result += (n % 10) * (*multiplier);
    *multiplier *= 10;
    reverseHelper(n / 10, result, multiplier);
}

int reverseNumber(int n) 
{
    int result = 0, multiplier = 1;
    int sign = (n < 0) ? -1 : 1;
    if (n < 0) n = -n;
    reverseHelper(n, &result, &multiplier);
    return sign * result;
}

int main() 
{
    int n;

    printf("Enter an integer: ");
    scanf("%d", &n);

    printf("Reverse of %d = %d\n", n, reverseNumber(n));

    return 0;
}
