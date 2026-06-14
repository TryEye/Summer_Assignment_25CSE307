#include <stdio.h>

int main() 
{
    int n, binary[32], index = 0;

    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    if (n == 0) 
      {
        printf("Binary of 0 = 0\n");
        return 0;
      }

    int temp = n;
    while (temp > 0) 
      {
        binary[index++] = temp % 2;
        temp /= 2;
      }

    printf("Binary of %d = ", n);
    for (int i = index - 1; i >= 0; i--) 
      {
        printf("%d", binary[i]);
      }
    printf("\n");

    return 0;
}
