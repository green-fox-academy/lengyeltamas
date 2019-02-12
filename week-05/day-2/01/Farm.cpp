#include "Farm.h"

Farm::Farm(int numberOfSlots)
{
    _numberOfSlots = numberOfSlots;
}

void Farm::breed()
{
    if (_numberOfSlots > _animal.size()) {
        Animal animal;
        _animal.push_back(animal);
    }
}

void Farm::slaughter()
{
    for (int i = 0; i < _animal.size(); ++i) {
        
    }
}

int Farm::getSizeOfAnimalVector()
{
    return _animal.size();
};
