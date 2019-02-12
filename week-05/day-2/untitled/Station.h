#ifndef UNTITLED_STATION_H
#define UNTITLED_STATION_H
#include "Car.h"
#include <string>

class Station
{
public:
    Station(int stationGasAmount);
    void fill(Car car);

private:
    int _gasAmount;
};

#endif //UNTITLED_STATION_H