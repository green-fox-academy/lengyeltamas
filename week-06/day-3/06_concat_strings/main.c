#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

// write a function which takes 2 strings as parameter, concatenates them together and returns it back.
// Test it for long and empty strings as well.
// Try to use the least amount of memory that's possible.

char * string_concatenate(char * input_one, char * input_two);

int main()
{
    puts(string_concatenate("hello-", "bello"));
    return 0;
}

char * string_concatenate(char * input_one, char * input_two)
{
    char * result;
    result = (char*)malloc( (strlen(input_one) + strlen(input_two) ) * sizeof(char));
    strcpy(result, input_one);
    strcat(result, input_two);
    return result;
}