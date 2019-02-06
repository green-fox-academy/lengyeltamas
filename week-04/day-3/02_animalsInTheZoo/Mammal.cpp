#include "Mammal.h"
std::string Mammal::breed()
{
    return "viviparous";
}
Mammal::Mammal(int numberOfLimbs)
{
    _numberOfLimbs = numberOfLimbs;
}