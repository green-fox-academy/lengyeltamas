#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Create a program which asks for the name of the user and stores it
    // Create a function which takes a string as a parameter and returns the length of it
    // Solve this exercise with and without using string.h functions

    printf("Type in your name please:\n");
    char name[20];
    scanf("%s", name);

    printf("%s, your name is %d characters long!\n", name,strlen(name));

    int length = 0;
    for (int i = 0; name[i] != '\0'; ++i) {
        length++;
    }

    printf("%s, your name is %d characters long!\n", name, length);

    return 0;
}