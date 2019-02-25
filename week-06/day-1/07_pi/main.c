#include <stdio.h>
#include <stdlib.h>
#define PI 3.14

// define a variable called PI with the value of 3.14
// create a function which takes the radius of a circle as a parameter
// and return the area of that circle
// area = radius * radius * PI

float calculateArea(float r)
{
    float area = (r * r * PI);
    return area;
}

int main()
{
    printf("Give me your circle's radius:\n");
    float radius;
    scanf("%f", &radius);
    printf("Your circle's area is: %.2f\n", calculateArea(radius));

	return 0;
}