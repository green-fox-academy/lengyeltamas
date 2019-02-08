#include <iostream>
#include "mentor.h"

std::string LevelToString (Level level)
{
    if (level == Level::JUNIOR) {
        return "junior";
    } else if (level == Level::INTERMEDIATE) {
        return "intermediate";
    } else {
        return "senior";
    }
}

Mentor::Mentor()
{
    _level = Level::INTERMEDIATE;
}

Mentor::Mentor(std::string name, int age, Gender gender, Level level) :
    Person(name, age, gender)
{
    _level = level;
}

void Mentor::getGoal()
{
    std::cout << "My goal is: Educate brilliant junior software developers." << std::endl;
}

void Mentor::introduce()
{
    std::cout << "Hi, I'm " <<
    _name << " , a " <<
    _age << " year old " <<
     LevelToString(_level) << " " <<
     GenderToString(_gender) << " mentor." << std::endl;
}