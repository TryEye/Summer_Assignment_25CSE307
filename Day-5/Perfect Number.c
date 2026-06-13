#include <stdio.h>

int main() {
    int n, sumOfFactors = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sumOfFactors += i;
        }
    }

    if (sumOfFactors == n) {
        printf("%d is a Perfect number.\n", n);
    } else {
        printf("%d is NOT a Perfect number.\n", n);
    }

    return 0;
}
