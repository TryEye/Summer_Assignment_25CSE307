#include <stdio.h>

int main() {
    long long n, largestFactor = -1;

    printf("Enter a positive integer: ");
    scanf("%lld", &n);

    long long temp = n;

    /* Divide by 2 first */
    while (temp % 2 == 0) {
        largestFactor = 2;
        temp /= 2;
    }

    /* Divide by odd factors from 3 onwards */
    for (long long i = 3; i * i <= temp; i += 2) {
        while (temp % i == 0) {
            largestFactor = i;
            temp /= i;
        }
    }

    /* If temp is still > 1, it's a prime factor */
    if (temp > 1) {
        largestFactor = temp;
    }

    printf("Largest prime factor of %lld = %lld\n", n, largestFactor);

    return 0;
}
