/*
 * Q10: Print prime numbers in a range
 * Day-3 | Admission No: 25CSAIM290
 */

#include <stdio.h>

int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int low, high;

    printf("Enter the lower bound: ");
    scanf("%d", &low);
    printf("Enter the upper bound: ");
    scanf("%d", &high);

    printf("\nPrime numbers between %d and %d:\n", low, high);
    for (int i = low; i <= high; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
