#include <stdio.h>
#include <math.h>

int main() {
    int n, sum = 0, digits = 0, digit;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    /* Count number of digits */
    int temp = n;
    while (temp != 0) {
        digits++;
        temp /= 10;
    }

    /* Calculate sum of each digit raised to power (digits) */
    temp = n;
    while (temp != 0) {
        digit = temp % 10;
        sum += (int)pow(digit, digits);
        temp /= 10;
    }

    if (sum == n) {
        printf("%d is an Armstrong number.\n", n);
    } else {
        printf("%d is NOT an Armstrong number.\n", n);
    }

    return 0;
}
