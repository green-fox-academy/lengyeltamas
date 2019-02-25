#include <stdio.h>

// print out the characters that corresponds to these ascii values

int main()
{


    int array[] = { 103, 114, 101, 101, 110, 32, 102, 111, 120};

    char string[sizeof(array)+1] = " ";
    for (int i = 0; i < sizeof(array); ++i) {
        string[i] = (char)array[i];
    }
    string[sizeof(array)] = 0;
    printf("%s", string);

    return 0;
}