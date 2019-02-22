#include <stdio.h>
#include <stdlib.h>

int integerCompare(int a, int b)
{
    return (a == b)? 1 : 0;
}

int main()
{
    // Create a program which asks for two integers and stores them separately
    // Create a function which takes two numbers as parameters and
    // returns 1 if they are equal and returns 0 otherwise

    printf("Give me an integer:\n");
    int num1;
    scanf("%d", &num1);
    printf("Give me another integer:\n");
    int num2;
    scanf("%d", &num2);

    printf("%d", integerCompare(num1, num2));

    return 0;
}