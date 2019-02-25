#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stringTester(char string[], char character)
{
    /*int result;
    char pResult = NULL;
    pResult = strchr(string, character);

    return result;
    did not finished yet*/
}

int main()
{
    // Create a program which asks for a string and a character and stores them
    // Create a function which takes a string and a character as a parameter and
    // if the given character is in the string, it should return the index of the
    // first appearance (in the given string) otherwise the function should return -1
    //
    // Example:
    //
    // Case 1:
    //
    // given_string = "embedded"
    // given_char = 'd'
    //
    // the function should return: 4, because this is the index of the first appearance of char 'd'
    //
    //
    // Case 2:
    //
    // given_string = "embedded"
    // given_char = 'a'
    //
    // the function should return: -1, because there is no 'a' in the word "embedded"
    //

    puts("Give me a string first:");
    char testString[100];
    gets(testString);
    printf("..and now give me a character:\n");
    char testChar;
    scanf("%c", testChar);
    printf("Result is: %d", stringTester(testString, testChar));

    return 0;
}