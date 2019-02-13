#include "Waiter.h"

Waiter::Waiter(int experience): Employees(experience)
{
    _tips = 0;
}

void Waiter::work()
{
    _tips++;
    _experience++;
}