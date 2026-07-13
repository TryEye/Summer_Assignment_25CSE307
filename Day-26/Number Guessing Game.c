#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int secretNumber, guess, attempts = 0;
    int maxAttempts = 7;

    
    srand((unsigned int)time(NULL));
    secretNumber = rand() % 100 + 1; 

    printf("========================================\n");
    printf("      Welcome to Number Guessing Game   \n");
    printf("========================================\n");
    printf("I have picked a number between 1 and 100.\n");
    printf("You have %d attempts to guess it.\n\n", maxAttempts);

    while (attempts < maxAttempts)
    {
        printf("Attempt %d/%d - Enter your guess: ", attempts + 1, maxAttempts);
        scanf("%d", &guess);
        attempts++;

        if (guess == secretNumber)
        {
            printf("\nCongratulations! You guessed it in %d attempt(s)!\n", attempts);
            return 0;
        } 
        else if (guess < secretNumber)
        {
            printf("Too low! Try a higher number.\n\n");
        } 
        else
        {
            printf("Too high! Try a lower number.\n\n");
        }
    }

    printf("\nGame Over! The secret number was %d.\n", secretNumber);

    return 0;
}
