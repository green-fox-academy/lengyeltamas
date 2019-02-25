#include <stdio.h>
#include <stdlib.h>

char * oldEnough (int testAge)
{
    if (testAge >= 18) {
        return "You are old enough to drink alcohol at hungary.";
    } else {
        return "You are not old enough to drink alcohol at hungary";
    }
}

int main()
{
    // Create a program which asks for the age of the user and stores it
    // Create a function which takes that age as a parameter and returns if the user is
    // old enough to buy himself alcohol in Hungary

    printf("Tell me your age:\n");
    int age;
    scanf("%d", &age);
    printf(oldEnough(age));

    return 0;
}