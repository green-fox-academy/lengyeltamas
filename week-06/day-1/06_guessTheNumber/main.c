#include <stdio.h>

int main()
{
    // Write a program that stores a number, and the user has to figure it out.
    // The user can input guesses, after each guess the program would tell one
    // of the following:
    //
    // The stored number is higher
    // The stored number is lower
    // You found the number: 8

    int storedNumber = 100;
    int guessNumber = 0;

    while(guessNumber != storedNumber) {

        printf("Give me a number:\n");
        scanf("%d", &guessNumber);

        if (guessNumber < storedNumber) {
            printf("The stored number is higher\n\n");
        } else if (guessNumber > storedNumber) {
            printf("The stored number is lower\n\n");
        } else {
            printf("You found the number: %d\n", guessNumber);
        }
    }
    return 0;
}