#include "Ship.h"
#include <iostream>

void Ship::addPirates(Pirate pirate)
{
    if(pirate.isCapitain()) {
        for (int i = 0; i < _pirates.size(); ++i) {
            if (_pirates[i].isCapitain())
                return;
        }
    }
    _pirates.push_back(pirate);
}

std::vector<std::string> Ship::getPoorPirates()
{
    std::vector<std::string> poorPirates;
    for (int i = 0; i < _pirates.size(); ++i) {
        if (_pirates[i].hasWoodenLeg() && _pirates[i].amountOfGold() < 15) {
            poorPirates.push_back(_pirates[i].get_name());
        }
    }
    return poorPirates;
}

int Ship::getGolds()
{
    int sumGold = 0;
    for (int i = 0; i < _pirates.size(); ++i) {
        sumGold += _pirates[i].amountOfGold();
    }
    return sumGold;
}

void Ship::lastDayOnTheShip()
{
    for (int i = 0; i < _pirates.size(); ++i) {
        _pirates[i].party();
    }
}

void Ship::prepareForBattle()
{
    for (int i = 0; i < _pirates.size(); ++i) {
        for (int j = 0; j < 5; ++j) {
            _pirates[i].work();
        }
    }
    lastDayOnTheShip();
}

void Ship::getPiratesFromShip()
{
    for (int i = 0; i < _pirates.size(); ++i) {
       std::cout << _pirates[i].get_name() << std::endl;
    }
}