#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * appendA(char * string);

int main()
{
    // Create a program which asks for a string and stores it
    // Create a function which takes a string as a parameter and
    // appends a character 'a' to the end of it and returns the new string
    puts("Give me a string:");
    char string[100];
    gets(string);
    puts(appendA(string));

    return 0;
}

char * appendA(char * string)
{
    char * result;
    char * letter = "A";
    result = strcat(string, letter);
    return result;
}