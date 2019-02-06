#include "BassGuitar.h"
BassGuitar::BassGuitar()
{
    _numberOfStrings = 4;
    _name = "Bass Guitar";
}

BassGuitar::BassGuitar(int numberOfStrings)
{
    _numberOfStrings = numberOfStrings;
    _name = "Bass Guitar";
}

std::string BassGuitar::sound()
{
    return "Duum-duum-duum";
}