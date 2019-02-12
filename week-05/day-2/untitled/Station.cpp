#include "Station.h"
#include <iostream>

Station::Station(int stationGasAmount)
{
    _gasAmount = stationGasAmount;
}

void Station::fill(Car car)
{
    while(!car.isFull() && _gasAmount > 0) {
    car.fill();
    std::cout << "Filling car!" << std::endl;
    _gasAmount--;
    }
    std::cout << _gasAmount << std::endl;
}