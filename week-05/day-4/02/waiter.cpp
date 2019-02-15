#include "waiter.h"

void Waiter::work()
{
    _tips++;
    _experience++;
}

Waiter::Waiter(std::string name, int experience) : Employee(name, experience)
{
}

int Waiter::get_tips() const
{
    return _tips;
}

std::string Waiter::toString()
{
    return "Hello, I'm " + _name +
           " a waiter, with " + std::to_string(_experience) +
           " experience points, and I earned " + std::to_string(_tips) +
           " EUR from tips today!";
}