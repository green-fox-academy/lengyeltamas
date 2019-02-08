#include "Mammal.h"

std::string isItFurryToString (Furry furry){
    if (furry == Furry::FURRY) {
        return "furry";
    } else {
        return "nope";
    }
};

Mammal::Mammal(std::string name, int age, Gender gender,
    Size size, Furry furry, int numberOfLimbs) :
    Animal(name, age, gender, size)
{
    _furry = furry;
    _numberOfLimbs = numberOfLimbs;
}

std::string Mammal::breed()
{
    return "viviparous";
}