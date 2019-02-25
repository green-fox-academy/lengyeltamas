#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculateWhereIsIt(char * testSentence,char character);

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

    puts("Give me a sentence:");
    char sentence[100];
    gets(sentence);
    printf("Now give me a character:\n");
    char character;
    scanf("%c", &character);
    printf("%d", calculateWhereIsIt(sentence, character));

    return 0;
}

int calculateWhereIsIt(char * testSentence, char character)
{
    int index;
    char * pointer;

    pointer = strchr(testSentence, character);

    if(pointer == NULL) {
        return -1;
    } else {
        index = pointer - testSentence;
        return index / sizeof(char);
    }
}
