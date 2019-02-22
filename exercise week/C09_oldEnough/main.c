#include <stdio.h>
#include <stdlib.h>


int areYouAllowed (int a)
{
    if(a < 18){
        return 0;
    } else {
        return 1;
    }
}

int main()
{
    // Create a program which asks for the age of the user and stores it
    // Create a function which takes that age as a parameter and returns if the user is
    // old enough to buy himself alcohol in Hungary

    int age;
    printf("Give me your age:\n");
    scanf("%d", &age);
    if (areYouAllowed(age) == 0) {
        printf("You are not allowed to drink alcohol in hungary, sorry");
    } else if (areYouAllowed(age) == 1) {
        printf("You are allowed to drink alcohol in hungary, have fun");
    }


    return 0;
}