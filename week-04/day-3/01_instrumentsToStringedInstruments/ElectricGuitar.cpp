#include "ElectricGuitar.h"

ElectricGuitar::ElectricGuitar() {
    _numberOfStrings = 6;
    _name = "Electric Guitar";
};

ElectricGuitar::ElectricGuitar(int numberOfStrings)
{
    _numberOfStrings = numberOfStrings;
    _name = "Electric Guitar";
};

std::string ElectricGuitar::sound()
{
    return "Twang";
}