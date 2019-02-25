#include<stdio.h>

int main()
{
    // Create a program that prints a few operations on two numbers: 22 and 13

    int a = 22;
    int b = 13;

    // Print the result of 13 added to 22

    printf("%d\n", a + b);

    // Print the result of 13 substracted from 22

    printf("%d\n", (a - b));

    // Print the result of 22 multiplied by 13

    printf("%d\n", (a * b));

    // Print the result of 22 divided by 13 (as a decimal fraction)

    printf("%f\n", ((float)a / (float)b));

    // Print the reminder of 22 divided by 13

    printf("%d\n", (a % b));

    // Store the results in variables and use them when you display the result

    return 0;
}