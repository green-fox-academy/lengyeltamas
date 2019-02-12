#ifndef INC_01_FARM_H
#define INC_01_FARM_H
#include "Animal.h"
#include <vector>

class Farm
{
public:
    Farm(int numberOfSlots, std::vector<Animal> alreadyCreatedAnimals);
    void breed();
    void slaughter();
    int getSizeOfAnimalVector();

protected:
    std::vector<Animal> _animal;
    int _numberOfSlots;
};

#endif //INC_01_FARM_H