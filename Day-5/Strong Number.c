#include <stdio.h>

long long factorial(int d) {
    long long f = 1;
    for (int i = 1; i <= d; i++) {
        f *= i;
    }
    return f;
}

int main() {
    int n, digit;
    long long sum = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    int temp = n;
    while (temp != 0) {
        digit = temp % 10;
        sum += factorial(digit);
        temp /= 10;
    }

    if (sum == n) {
        printf("%d is a Strong number.\n", n);
    } else {
        printf("%d is NOT a Strong number.\n", n);
    }

    return 0;
}
