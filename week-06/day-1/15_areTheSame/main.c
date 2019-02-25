#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculateAreTheSame(const char * testSentence1, const char * testSentence2);

int main()
{
    // Create a program which asks for two strings and stores them
    // Create a function which takes two strings as parameters and
    // returns 1 if the two strings are the same and 0 otherwise
    // Try to erase small and uppercase sensitivity.

    puts("Give me a sentence:");
    char sentence1[100];
    gets(sentence1);
    puts("Now give me another one:");
    char sentence2[100];
    gets(sentence2);
    printf("%d", calculateAreTheSame(sentence1, sentence2));
    return 0;
}
int calculateAreTheSame(const char * testSentence1, const char * testSentence2)
{
    int result = 0;
    if(strcmp(testSentence1, testSentence2) == 0) {
        result = 1;
    }
    return result;
}