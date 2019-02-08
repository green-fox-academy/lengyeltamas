#include "person.h"
#include <iostream>

std::string GenderToString (Gender gender)
{
    if (gender == Gender::FEMALE) {
        return "female";
    } else {
        return "male";
    }
}

Person::Person(){
    _name = "Jane Doe";
    _age = 30;
    _gender = Gender::FEMALE;
}



Person::Person(std::string name, int age, Gender gender)
{
    _name = name;
    _age = age;
    _gender = gender;
}

void Person::introduce ()
{
    std::cout << "Hi, I'm " <<
    _name << ", a " <<
    _age << " year old " <<
    GenderToString(_gender) << std::endl;
}

void Person::getGoal()
{
    std::cout <<  "My goal is: Live for the moment!" << std::endl;
}