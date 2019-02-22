#include <stdio.h>
#include <stdlib.h>

// define a variable called PI with the value of 3.14
// create a function which takes the radius of a circle as a parameter
// and return the area of that circle
// area = radius * radius * PI

#define PI 3.14

float circleAreaCalculator (float r) {
    float area = (r * r * PI);
    return area;
}

int main()
{
    float radius;
    printf("Give me your circle's radius:");
    scanf("%f", &radius);
    printf("Your circle's area is: %f\n", circleAreaCalculator(radius));
	return 0;
}