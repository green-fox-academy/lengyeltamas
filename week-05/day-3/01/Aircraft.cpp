#include "Aircraft.h"

std::string aircraftToString (AircraftType aircraftType)
    {
        if (aircraftType == AircraftType::F16) {
            return "F16";
        } else {
            return "F35";
        }
    };

Aircraft::Aircraft(AircraftType aircraftType)
{
    _aircraftType = aircraftType;
    if (aircraftType == F16) {
        _maxAmmo = 8;
        _baseDamage = 30;
        _ammoAmount = 0;
    } else {
        _maxAmmo = 12;
        _baseDamage = 50;
        _ammoAmount = 0;
    }
}

AircraftType Aircraft::get_aircraftType() const
{
    return _aircraftType;
}

int Aircraft::get_maxAmmo() const
{
    return _maxAmmo;
}

int Aircraft::get_baseDamage() const
{
    return _baseDamage;
}

int Aircraft::get_ammoAmount() const
{
    return _ammoAmount;
}

int Aircraft::fight() {
    int usedAmmos = 0;
    while (_ammoAmount == 0) {
        usedAmmos++;
        _ammoAmount--;
    }
    return (usedAmmos * _baseDamage);
};

int Aircraft::refill(int fillingAmmo)
{
    int remainingAmmo;
    if (fillingAmmo >= _maxAmmo) {
        _ammoAmount = _maxAmmo;
        remainingAmmo = fillingAmmo - _ammoAmount;
    } else {
        _ammoAmount = fillingAmmo;
        remainingAmmo = 0;
    }
    return remainingAmmo;
}

std::string Aircraft::getType()
{
    return aircraftToString(get_aircraftType());
}

