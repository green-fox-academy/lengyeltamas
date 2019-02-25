#include <stdio.h>
#include <stdlib.h>

int isEqual(int testNum1, int testNum2)
{
    if (testNum1 == testNum2) {
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    // Create a program which asks for two integers and stores them separately
    // Create a function which takes two numbers as parameters and
    // returns 1 if they are equal and returns 0 otherwise

    printf("Give me a number:\n");
    int number1;
    scanf("%d", &number1);
    printf("Give me another number:\n");
    int number2;
    scanf("%d", &number2);

    printf("%d", isEqual(number1, number2));

    return 0;
}