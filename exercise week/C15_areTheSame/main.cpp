#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Create a program which asks for two strings and stores them
    // Create a function which takes two strings as parameters and
    // returns 1 if the two strings are the same and 0 otherwise
    // Try to erase small and uppercase sensitivity.

    printf("Tell me something:\n");
    char firstString[100];
    scanf("%s", firstString);
    printf("Tell me some more shit:\n");
    char secondString[100];
    scanf("%s", secondString);

    int result = strcasecmp(firstString, secondString);

    if(result == 0) {
        result = 1;
    } else if (result == 1) {
        result = 0;
    }

    printf("The result is: %d", result);

    return 0;
}