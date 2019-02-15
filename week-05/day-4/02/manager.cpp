#include "manager.h"

Manager::Manager(std::string name, int experience) : Employee(name, experience)
{
}

void Manager::work()
{
    _experience++;
    haveAMeeting();
}

void Manager::haveAMeeting()
{
    _moodLevel -= _experience;
}

int Manager::get_moodLevel() const
{
    return _moodLevel;
}

std::string Manager::toString()
{
    return "Hello, I'm " + _name +
    " a manager, with " + std::to_string(_experience) +
    " experience points, and my mood level after this day is: " + std::to_string(_moodLevel);
}
