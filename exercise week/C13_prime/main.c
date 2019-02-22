#include <stdio.h>
#include <stdlib.h>

int primeFinder(int testNum)
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
        result = 1;
    }

    return result;
}

int main()
{
    // Create a program which asks for a number and stores it
    // Create a function which takes a number as a parameter
    // and returns 1 if the number is a prime number and 0 otherwise
    // (in this case 0 is not considered as a prime number)

    printf("Give me a number:\n");
    int num;
    scanf("%d", &num);
    printf("%d", primeFinder(num));

    return 0;
}