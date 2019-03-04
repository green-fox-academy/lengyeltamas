#include <stdio.h>

// print out the characters that corresponds to these ascii values

int main()
{


    int array[] = {103, 114, 101, 101, 110, 32, 102, 111, 120};

    char string[(sizeof(array)/sizeof(int))];
    for (int i = 0; i <= sizeof(string); ++i) {
        string[i] = (char)array[i];
    }
    printf("%s", string);

    return 0;
}