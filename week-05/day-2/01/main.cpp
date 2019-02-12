#include <iostream>
#include "Animal.h"
#include "Farm.h"

int main()
{
    Farm testfarm(4);

    testfarm.breed();
    testfarm.breed();
    testfarm.breed();
    testfarm.breed();
    testfarm.breed();

    std::cout << testfarm.getSizeOfAnimalVector();


    return 0;
}