#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

// write a function which takes a string and an integer as a parameter.
// The function should return a string where the input string is repeating.
// The number of repetition is based on the value of the integer parameter.
// For example: Apple, 5 -> AppleAppleAppleAppleApple
// Try to use the least amount of memory that's possible.

char * string_repeat (char * input_string, int input_number);

int main()
{
    puts(string_repeat("Apple", 5));
    return 0;
}

char * string_repeat (char * input_string, int input_number)
{
    char * result;
    result = (char *)malloc(((strlen(input_string) * input_number) * sizeof(char)));
    strcpy(result, input_string);
    for (int i = 0; i < input_number - 1; ++i) {
        strcat(result, input_string);
    }
    return result;
}