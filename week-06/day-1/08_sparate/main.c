#include <stdio.h>
#include <stdlib.h>
#include "area.h"
// define a variable called PI with the value of 3.14
// create a function which takes the radius of a circle as a parameter
// and return the area of that circle
// area = radius * radius * PI


int main()
{
    printf("Give me your circle's radius:\n");
    float radius;
    scanf("%f", &radius);
    printf("Your circle's area is: %.2f\n", AREA);

    return 0;
}