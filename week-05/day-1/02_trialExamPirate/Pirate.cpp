#include "Pirate.h"
#include <iostream>

Pirate::Pirate(std::string name, bool isCapitain, bool hasWoodenLeg)
{
    _name = name;
    _amountOfGold = 0;
    _healthPoint = 10;
    _isCapitain = isCapitain;
    _hasWoodenLeg = hasWoodenLeg;
}

void Pirate::work()
{
    if (_isCapitain) {
        _amountOfGold += 10;
        _healthPoint -= 5;
    } else {
        _amountOfGold++;
        _healthPoint--;
    }
}

void Pirate::party()
{
    if (_isCapitain) {
        _healthPoint += 10;
    } else {
        _healthPoint += 1;
    }
}

std::string Pirate::toString()
{
    if (_hasWoodenLeg) {
        return "Hello, I'm " + _name + ". I have a wooden leg and " + std::to_string(_amountOfGold) + " golds.";
    } else {
        return "Hello, I'm " + _name + ". I still have my real legs and " + std::to_string(_amountOfGold) + " golds.";
    }
}

bool Pirate::isCapitain() const
{
    return _isCapitain;
}

bool Pirate::hasWoodenLeg() const
{
    return _hasWoodenLeg;
}

int Pirate::amountOfGold() const
{
    return _amountOfGold;
}

const std::string &Pirate::get_name() const
{
    return _name;
}