#include <stdio.h>

int main() 
{
    int n, product = 1, digit;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    int temp = n;
    while (temp != 0) 
    {
        digit = temp % 10;
        product *= digit;
        temp /= 10;
    }

    printf("Product of digits of %d = %d\n", n, product);

    return 0;
}
