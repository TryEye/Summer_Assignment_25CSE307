#include <stdio.h>
#include <math.h>

int isArmstrong(int num) {
    int sum = 0, digits = 0, digit, temp = num;

    while (temp != 0) {
        digits++;
        temp /= 10;
    }

    temp = num;
    while (temp != 0) {
        digit = temp % 10;
        sum += (int)pow(digit, digits);
        temp /= 10;
    }

    return (sum == num);
}

int main() {
    int low, high;

    printf("Enter lower bound: ");
    scanf("%d", &low);
    printf("Enter upper bound: ");
    scanf("%d", &high);

    printf("\nArmstrong numbers between %d and %d:\n", low, high);
    for (int i = low; i <= high; i++) {
        if (isArmstrong(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
