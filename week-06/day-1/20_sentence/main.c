#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter,
// and splits a string to words by space
// solve the problem with the proper string.h function

void stringSlicer(char testString [256]);

int main()
{
    printf("Type in a sentence:\n\n");
    char string[256];
    gets(string);
    stringSlicer(string);

    return(0);
}
void stringSlicer(char testString [256]) {
    for (char *p = strtok(testString, " "); p != NULL; p = strtok(NULL, " ")) {
        puts(p);
    }
}