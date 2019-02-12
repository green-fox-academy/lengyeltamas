#include "Farm.h"

Farm::Farm(int numberOfSlots, std::vector<Animal> alreadyCreatedAnimals)
{
    _animal = alreadyCreatedAnimals;
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
    int temp = _animal[0].get_hunger();
    for (int i = 0; i < _animal.size(); ++i) {
        if (_animal[i].get_hunger() < temp) {
            temp = _animal[i].get_hunger();
        }
    }

    for (int j = 0; j < _animal.size(); ++j) {
        if (_animal[j].get_hunger() == temp) {
            _animal.erase(_animal.begin()+j);
            _numberOfSlots++;
            break;
        }
    }
}

int Farm::getSizeOfAnimalVector()
{
    return _animal.size();
};