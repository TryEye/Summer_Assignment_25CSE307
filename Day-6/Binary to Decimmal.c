#include <stdio.h>
#include <math.h>

int main() 
{
    long long binaryNum;
    int decimal = 0, base = 1, digit;

    printf("Enter a binary number: ");
    scanf("%lld", &binaryNum);

    long long temp = binaryNum;
    while (temp != 0) 
    {
        digit = temp % 10;
        if (digit != 0 && digit != 1) 
   {
            printf("Invalid binary number!\n");
            return 1;
        }
        decimal += digit * base;
        base *= 2;
        temp /= 10;
    }

    printf("Decimal of %lld = %d\n", binaryNum, decimal);

    return 0;
}
