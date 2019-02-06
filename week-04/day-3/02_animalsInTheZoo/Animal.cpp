#include "Animal.h"

std::string genderToString (Gender gender) {
    if (gender == Gender::FEMALE) {
        return "female";
    } else {
        return "male";
    }
}

std::string sizeToString (Size size) {
    if (size == Size::TINY) {
        return "tiny";
    } else if (size == Size::REGULAR) {
        return "regular";
    } else {
        return "OMG";
    }
}

Animal::Animal(std::string name, int age, Gender gender, Size size)
{
    _name = name;
    _age = age;
    _gender = gender;
    _size = size;

}

std::string Animal::getName()
{
    return _name;
}