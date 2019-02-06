#ifndef INC_02_ANIMALSINTHEZOO_ANIMAL_H
#define INC_02_ANIMALSINTHEZOO_ANIMAL_H

#include <string>

enum Gender {
    MALE,
    FEMALE
};

std::string genderToString (Gender gender);

enum Size {
    TINY,
    REGULAR,
    OMG
};

std::string sizeToString (Size size);

class Animal
{
public:
    Animal(std::string name, int age, Gender gender, Size size);
    std::string getName();
    virtual std::string breed() = 0;

protected:
    std::string _name;
    int _age;
    Gender _gender;
    Size _size;

};

#endif //INC_02_ANIMALSINTHEZOO_ANIMAL_H