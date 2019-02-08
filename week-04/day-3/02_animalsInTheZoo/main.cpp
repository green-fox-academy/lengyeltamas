#include <iostream>
#include "Animal.h"
#include "Mammal.h"

int main()
{
    // animal (name, age, color, gender, size)
    // mammal (animal + isItFurry, numberOfLimbs)
    Mammal Doggo ("Dog", 2, "Brown", MALE, TINY, FURRY, 4);
    Mammal Tiger ("Tiger", 4, "TigerStripped", MALE, REGULAR, FURRY, 4);
}