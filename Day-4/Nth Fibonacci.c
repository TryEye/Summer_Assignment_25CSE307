#include <stdio.h>

int main() {
    int n;
    long long a = 0, b = 1, next;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
    } else if (n == 1) {
        printf("The %dth Fibonacci term = 0\n", n);
    } else if (n == 2) {
        printf("The %dth Fibonacci term = 1\n", n);
    } else {
        for (int i = 3; i <= n; i++) {
            next = a + b;
            a = b;
            b = next;
        }
        printf("The %dth Fibonacci term = %lld\n", n, b);
    }

    return 0;
}
