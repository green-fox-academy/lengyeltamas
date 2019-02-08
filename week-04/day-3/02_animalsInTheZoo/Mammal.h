#ifndef INC_02_ANIMALSINTHEZOO_MAMMAL_H
#define INC_02_ANIMALSINTHEZOO_MAMMAL_H
#include "Animal.h"

enum Furry {
    FURRY,
    NOPE
};

std::string isItFurryToString (Furry furry);

class Mammal : public Animal
{
public:
    Mammal();
    Mammal(std::string name, int age, Gender gender, Size size, Furry furry, int numberOfLimbs);
    virtual std::string breed() override;

private:
    Furry _furry;
    int _numberOfLimbs;
};

#endif //INC_02_ANIMALSINTHEZOO_MAMMAL_H