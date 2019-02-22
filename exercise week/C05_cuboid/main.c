#include <stdio.h>

int main()
{
    // Write a program that stores 3 sides of a cuboid as variables (doubles)
    // You should get these variables via console input
    // The program should write the surface area and volume of the cuboid like:
    //
    // Surface Area: 600
    // Volume: 1000

    float a;
    float b;
    float c;

    printf("Give me the cuboid's width\n");
    scanf("%f", &a);

    printf("Give me the cuboid's length\n");
    scanf("%f", &b);

    printf("Give me the cuboid's height\n");
    scanf("%f", &c);

    float surface = (a * b);
    float volume = (surface * c);

    printf("Surface Area: %f\n", surface);
    printf("Volume: %f\n", volume);

    return 0;
}