#include <stdio.h>

double maximum(double a, double b) 
{
    return (a > b) ? a : b;
}

int main() 
{
    double a, b;

    printf("Enter two numbers: ");
    scanf("%lf %lf", &a, &b);

    printf("Maximum of %.2lf and %.2lf = %.2lf\n", a, b, maximum(a, b));

    return 0;
}
