#include "Carrier.h"

Carrier::Carrier(int carrierAmmo, int carrierHealthPoint)
{
    _carrierAmmo = carrierAmmo;
    _carrierHealthPoint = carrierHealthPoint;
}

const std::vector<Aircraft> &Carrier::get_aircrafts() const
{
    return _aircrafts;
}

int Carrier::get_carrierAmmo() const
{
    return _carrierAmmo;
}

int Carrier::get_carrierHealthPoint() const
{
    return _carrierHealthPoint;
}

void Carrier::add(Aircraft aircraft)
{
    _aircrafts.push_back(aircraft);
}

