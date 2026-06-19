#include <stdio.h>

double sum(double a, double b) 
{
    return a + b;
}

int main() 
{
    double a, b;

    printf("Enter two numbers: ");
    scanf("%lf %lf", &a, &b);

    printf("Sum of %.2lf and %.2lf = %.2lf\n", a, b, sum(a, b));

    return 0;
}
