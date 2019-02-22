#include <stdio.h>
#include <stdlib.h>
#include "calculate.h"
/*
Continue working on the pi.c project

Organise the function from the previous exercise to separate .c and .h files

Create another function which calculates the circumference of a circle
    the radius of the circle should be passed as a parameter
    the function should return the calculated circumference
    circumference = 2 * radius * PI
    this function should be in the same .c and .h files as the one which calculates the area
 */

int main()
{
    float radius;
    printf("Give me your circle's radius:");
    scanf("%f", &radius);
    printf("Your circle's area is: %f\n", AREA);
    printf("Your circle's circumference is: %f\n", CIRCUMFERENCE);
    return 0;
}