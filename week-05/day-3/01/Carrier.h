#ifndef INC_01_CARRIER_H
#define INC_01_CARRIER_H
#include "Aircraft.h"
#include <vector>

class Carrier
{
public:
    Carrier(int carrierAmmo, int carrierHealthPoint);

    const std::vector<Aircraft> &get_aircrafts() const;

    int get_carrierAmmo() const;

    int get_carrierHealthPoint() const;

    void add(Aircraft aircraft);

    void fill();

private:
    std::vector<Aircraft> _aircrafts;

    int _carrierAmmo;

    int _carrierHealthPoint;
};

#endif //INC_01_CARRIER_H