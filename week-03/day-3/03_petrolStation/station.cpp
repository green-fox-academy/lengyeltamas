#include "station.h"
#include <iostream>

station::station()
{
    gasAmount = 100;
}

void station::fill(Car car) {
    while(car.isFull()) {
        car.fill();
        std::cout << "Filling car!" << std::endl;
        gasAmount--;
    }
    std::cout << gasAmount << std::endl;
}