#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculateLength(const char * testName);

int main()
{
    // Create a program which asks for the name of the user and stores it
    // Create a function which takes a string as a parameter and returns the length of it
    // Solve this exercise with and without using string.h functions

    printf("Give me your name:\n");
    char name[10];
    scanf("%s", name);
    printf("%d", calculateLength(name));

    return 0;
}

int calculateLength(const char * testName) {
    return strlen(testName);
}
