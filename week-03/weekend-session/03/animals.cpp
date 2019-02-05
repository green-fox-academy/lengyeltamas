#include <iostream>
#include "animals.h"

animals::animals() {}

void animals::eat()
{
    _hunger--;
}

void animals::drink()
{
    _thirst--;
}

void animals::play()
{
    _hunger++;
    _thirst++;
}

int animals::getHunger() const {
    return _hunger;
}


int animals::getThirst() const {
    return _thirst;
}
