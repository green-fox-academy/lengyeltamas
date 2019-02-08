#include <iostream>
#include "Animal.h"
#include "Mammal.h"

int main()
{
    // animal (name, age, gender, size)
    // mammal (animal + isItFurry, numberOfLimbs)
    Mammal Doggo ("Dog", 2, MALE, TINY, FURRY, 4);
    Mammal Tiger ("Tiger", 4, MALE, REGULAR, FURRY, 4);
}