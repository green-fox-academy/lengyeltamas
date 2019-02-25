#include<stdio.h>

int main()
{
    // Write a program that prints a few details to the terminal window about you
    // It should print each detail to a new line.
    //  - Your name
    //  - Your age
    //  - Your height in meters (as a decimal fraction)
    //
    //  Use variables to store the informations!
    //
    //  Example output:
    //  John Doe
    //  31
    //  1.87

    char * name = "Lengyel Tamas";
    int age = 33;
    float height = 1.95;

    printf("- name: %s\n- age: %d\n- height: %.2f", name, age, height);

    return 0;
}