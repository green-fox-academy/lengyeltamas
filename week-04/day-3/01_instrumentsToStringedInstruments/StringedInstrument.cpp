#include "StringedInstrument.h"
#include <iostream>

void StringedInstrument::play()
{
    std::cout << _name << " , a " <<
    _numberOfStrings << "-stringed instrument that goes " <<
    sound() << std::endl;
}