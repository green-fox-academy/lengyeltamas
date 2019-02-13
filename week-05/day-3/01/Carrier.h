#ifndef INC_01_CARRIER_H
#define INC_01_CARRIER_H
#include "Aircraft.h"
#include <vector>

class Carrier
{
public:
    Carrier(int carrierAmmo, int carrierHealthPoint);

    void add(Aircraft aircraft);

    const std::vector<Aircraft> &get_aircrafts() const;

    int get_carrierAmmo() const;

    int get_carrierHealthPoint() const;

private:
    std::vector<Aircraft> _aircrafts;

    int _carrierAmmo;

    int _carrierHealthPoint;
};

#endif //INC_01_CARRIER_H