#ifndef INC_02_ANIMALSINTHEZOO_MAMMAL_H
#define INC_02_ANIMALSINTHEZOO_MAMMAL_H
#include "Animal.h"

class Mammal : public Animal
{
public:
    Mammal(int numberOfLimbs);
    std::string breed();
private:
    int _numberOfLimbs;
};

#endif //INC_02_ANIMALSINTHEZOO_MAMMAL_H