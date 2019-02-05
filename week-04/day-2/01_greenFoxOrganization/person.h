#ifndef INC_01_GREENFOXORGANIZATION_PERSON_H
#define INC_01_GREENFOXORGANIZATION_PERSON_H

#include <string>

enum Gender {
    MALE,
    FEMALE
};

std::string GenderToString (Gender gender);

class Person
{
public:
    Person();
    Person(std::string name, int age, Gender gender);
    virtual void introduce();
    virtual void getGoal();

protected:
    std::string _name;
    int _age;
    Gender _gender;
};


#endif //INC_01_GREENFOXORGANIZATION_PERSON_H
