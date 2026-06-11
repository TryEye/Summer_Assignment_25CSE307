/*
 * Q12: Find LCM of two numbers
 * Day-3 | Admission No: 25CSAIM290
 */

#include <stdio.h>

int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a, b;
    long long lcm;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    lcm = (long long)a / gcd(a, b) * b;

    printf("LCM of %d and %d = %lld\n", a, b, lcm);

    return 0;
}
