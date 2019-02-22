#include <stdio.h>
#include <stdlib.h>

int sumOfDigits(int testNum1, int testNum2)
{
    int remainder1;
    int sum1 = 0;

    while (testNum1 != 0) {
        remainder1 = testNum1 % 10;
        sum1 += remainder1;
        testNum1 /= 10;
    }

    int remainder2;
    int sum2 = 0;

    while (testNum2 != 0) {
        remainder2 = testNum2 % 10;
        sum2 += remainder2;
        testNum2 /= 10;
    }

    return ((sum1 == sum2)? 1 : 0);
}

int main()
{
    // Create a program which asks for two numbers and stores them
    // Create a function which takes two numbers as parameters
    // and returns 1 if the sum of the number of digits are equal and 0 otherwise
    //
    // For example:
    //
    // Case 1:
    //
    // a = 123
    // b = 321
    //
    // sum of number of digits (variable a) = 1 + 2 + 3 = 6
    // sum of number of digits (variable b) = 3 + 2 + 1 = 6
    // in this case the function should return 1
    //
    //
    // Case 2:
    //
    // a = 723
    // b = 114
    //
    // sum of number of digits (variable a) = 7 + 2 + 3 = 12
    // sum of number of digits (variable b) = 1 + 1 + 4 = 6
    // in this case the function should return 0

    printf("Give me a number:\n");
    int num1;
    scanf("%d", &num1);
    printf("Give me another number:\n");
    int num2;
    scanf("%d", &num2);
    printf("%d", sumOfDigits(num1, num2));

    return 0;
}