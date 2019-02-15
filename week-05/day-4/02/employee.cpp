#include "employee.h"

Employee::Employee(std::string name, int experience)
{
    _name = name;
    _experience = experience;
}

const std::string &Employee::get_name() const
{
    return _name;
}

int Employee::get_experience() const
{
    return _experience;
}
