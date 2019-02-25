#include <stdio.h>

int main()
{
    // Write a program that stores 3 sides of a cuboid as variables (doubles)
    // You should get these variables via console input
    // The program should write the surface area and volume of the cuboid like:
    //
    // Surface Area: 600
    // Volume: 1000

    printf("Give me the cuboid's width:\n");
    float width;
    scanf("%f\n", &width);
    printf("Give me the cuboid's depth:\n");
    float depth;
    scanf("%f\n", &depth);
    printf("Give me the cuboid's height:\n");
    float height;
    scanf("%f\n", &height);

    printf("Your cuboid's surface area is: %.2f", (((width*depth)*2) + ((width*height)*2)) + ((depth*height)*2));
    printf("Your cuboid's volume is: %.2f", (width * depth * height));

    return 0;
}