#include "Animal.h"

void Animal::heal()
{
    _isHealthy = true;
}

bool Animal::isAdoptable()
{
    if(_isHealthy = true) {
        return true;
    } else {
        return false;
    }
}

std::string Animal::toString()
{
    if (_isHealthy = false) {
        return  _name + " is not healthy (< " + std::to_string(_healCost)  + " >€), and not adoptable";
    } else {
        return _name + " is healthy, and adoptable";
    }
}