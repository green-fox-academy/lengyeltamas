#include <stdio.h>
#include <stdlib.h>

int calculatePrime(int testnum);

int main()
{
    // Create a program which asks for a number and stores it
    // Create a function which takes a number as a parameter
    // and returns 1 if the number is a prime number and 0 otherwise
    // (in this case 0 is not considered as a prime number)

    printf("Give me a number to check if it's a prime number or not:\n");
    int number;
    scanf("%d", &number);
    printf("%d", calculatePrime(number));

    return 0;
}

int calculatePrime(int testNum)
{
    int result = 1;
    if (testNum > 1) {
        for (int i = 2; i <= testNum / 2; ++i) {
            if (testNum % i == 0) {
                result = 0;
                break;
            }
        }
    } else {
        result = 0;
    }
    return result;
}