/*
 * Q11: Find GCD of two numbers
 * Day-3 | Admission No: 25CSAIM290
 */

#include <stdio.h>

int main() {
    int a, b, temp;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    int x = a, y = b;

    /* Euclidean algorithm */
    while (y != 0) {
        temp = y;
        y = x % y;
        x = temp;
    }

    printf("GCD of %d and %d = %d\n", a, b, x);

    return 0;
}
