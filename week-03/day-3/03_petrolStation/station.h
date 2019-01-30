#ifndef INC_03_PETROLSTATION_STATION_H
#define INC_03_PETROLSTATION_STATION_H

#include "car.h"

class station
        {
public:
    station();

    void fill(Car car);

private:
    int gasAmount;
};


#endif //INC_03_PETROLSTATION_STATION_H
