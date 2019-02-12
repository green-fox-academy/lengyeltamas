#include <iostream>
#include "Animal.h"
#include "Farm.h"

int main()
{
    Animal cat;
    Animal dog;
    Animal seal;

    std::vector<Animal> myvector;
    myvector.push_back(cat);
    myvector.push_back(dog);
    myvector.push_back(seal);

    Farm testfarm(5, myvector);
    testfarm.breed();
    testfarm.breed();
    testfarm.breed();

    std::cout << testfarm.getSizeOfAnimalVector() << std::endl;

    testfarm.slaughter();

    std::cout << testfarm.getSizeOfAnimalVector() << std::endl;

    return 0;
}