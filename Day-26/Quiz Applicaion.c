#include <stdio.h>
#include <string.h>

int main()
{
    
    char questions[5][200] = 
    {
        "Q1. What does CPU stand for?\n   a) Central Processing Unit\n   b) Computer Personal Unit\n   c) Central Program Utility\n   d) Core Processing Unit",
        "Q2. Which language is used for C programming?\n   a) Python\n   b) Java\n   c) C\n   d) Ruby",
        "Q3. What is the output of 5 / 2 in C (integer division)?\n   a) 2.5\n   b) 2\n   c) 3\n   d) 0",
        "Q4. What symbol is used for address-of operator in C?\n   a) *\n   b) &\n   c) #\n   d) @",
        "Q5. Which function is used to print output in C?\n   a) print()\n   b) echo()\n   c) printf()\n   d) display()"
    };

    char answers[5] = {'a', 'c', 'b', 'b', 'c'};
    int score = 0;
    char choice;

    printf("====================================\n");
    printf("        C Programming Quiz          \n");
    printf("====================================\n\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", questions[i]);
        printf("Your answer: ");
        scanf(" %c", &choice);

        if (choice == answers[i])
        {
            printf("Correct!\n\n");
            score++;
        } 
        else
        {
            printf("Wrong! Correct answer: %c\n\n", answers[i]);
        }
    }

    printf("====================================\n");
    printf("Your Score: %d / 5\n", score);

    if (score == 5)      printf("Excellent! Perfect score!\n");
    else if (score >= 3) printf("Good job! Keep it up!\n");
    else                 printf("Keep practicing! You can do better.\n");

    return 0;
}
