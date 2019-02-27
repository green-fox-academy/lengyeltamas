#include <stdio.h>
#include <stdlib.h>

// Prompt the user to enter a number. -> This number will be X.
// Allocate memory for X numbers.
// Prompt the user to enter X numbers.
// Allocate memory for Y numbers, which is the sum of the X numbers.
// Fill that array with from 1 to Y, then print them.

int main()
{
    int* pointer = NULL;
    printf("Give me how many numbers do you want to enter:\n");
    int X = 0;
    scanf("%d", &X);
    pointer = (int*)malloc(X * sizeof(int));
    for (int i = 0; i < X; ++i) {
        printf("Give me your number %d:\n", i+1);
        scanf("%d", &pointer[i]);
    }
    int Y = 0;
    for (int i = 0; i < X; ++i) {
        Y += pointer[i];
    }

    realloc(pointer, (Y * sizeof(int)));

    for (int j = 0; j < Y; ++j) {
        printf("Give me the number %d element's value:\n", j+1);
        scanf("%d", &pointer[j]);
    }

    for (int i = 0; i < Y; ++i) {
        printf("The value of element nr. %d is: %d\n", i+1, pointer[i]);
    }
    return 0;
}