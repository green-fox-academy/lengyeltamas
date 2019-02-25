#include <stdio.h>
#include <stdlib.h>

int calculateOddOrEven(int testNum)
{
    if (testNum % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    // Create a program which asks for a number and stores it
    // Create a function which takes a number as a parameter and
    // returns 1 if that number is even and returns 0 otherwise
    // (in this case 0 is an even number)

    printf("Give me a number:\n");
    int number;
    scanf("%d", &number);
    printf("%d", calculateOddOrEven(number));

    return 0;
}