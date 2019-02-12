#include "Car.h"

Car::Car(int gasAmount, int capacity)
{
    _gasAmount = gasAmount;
    _capacity = capacity;
}

bool Car::isFull()
{
    return (_gasAmount == _capacity);
}

void Car::fill()
{
    if (_gasAmount < _capacity) {
        _gasAmount++;
    }
}