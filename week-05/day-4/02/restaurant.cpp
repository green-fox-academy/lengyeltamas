#include "restaurant.h"

Restaurant::Restaurant(std::string name, int founded)
{
    _name = name;
    _founded = founded;
}

void Restaurant::guestArrived()
{
    for (int i = 0; i < _employees.size(); ++i) {
        _employees[i]->work();
    }
}

void Restaurant::hire(Employee &employee)
{
    _employees.push_back(&employee);
}

int Restaurant::get_founded() const
{
    return _founded;
}

const std::string &Restaurant::get_name() const
{
    return _name;
}

std::string Restaurant::toString()
{
    return "Hello, I'm " + _name +
           " a restaurant, founded in: " + std::to_string(_founded) +
           " and my employees are:\n" + vectorToString();
}

std::string Restaurant::vectorToString()
{
    std::string result;

    for (int i = 0; i < _employees.size(); ++i) {
        result.append(_employees[i]->get_name() + " ");
    }

    return result;
}

const std::vector<Employee *> &Restaurant::get_employees() const
{
    return _employees;
}
