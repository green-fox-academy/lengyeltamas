#include<stdio.h>

int main()
{
    // Create a program that prints a few operations on two numbers: 22 and 13

    // Print the result of 13 added to 22

    // Print the result of 13 substracted from 22

    // Print the result of 22 multiplied by 13

    // Print the result of 22 divided by 13 (as a decimal fraction)

    // Print the reminder of 22 divided by 13

    // Store the results in variables and use them when you display the result

    int num1 = 22;
    int num2 = 13;

    int addition = num1 + num2;
    printf("The result after addition is: %d\n", addition);

    int substraction = num1 - num2;

    printf("The result after the smaller numbers substraction is: %d\n", substraction);

    int multiplication = num1 * num2;

    printf("The result after multiplication is: %d\n", multiplication);

    float a = num1;
    float b = num2;
    float division = a / b;

    printf("The result after division is: %f\n", division);

    int reminder = num1 % num2;

    printf("The reminder after division is: %d\n", reminder);

    return 0;
}