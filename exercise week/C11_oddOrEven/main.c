#include <stdio.h>
#include <stdlib.h>

int oddOrEven(int testnum)
{
    return (testnum % 2 == 0)? 1 : 0;
}

int main()
{
    // Create a program which asks for a number and stores it
    // Create a function which takes a number as a parameter and
    // returns 1 if that number is even and returns 0 otherwise
    // (in this case 0 is an even number)

    printf("Give me a number:");
    int num;
    scanf("%d", &num);
    printf("%d", oddOrEven(num));

    return 0;
}