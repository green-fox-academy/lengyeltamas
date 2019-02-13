#include <iostream>
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

void Carrier::fill()
{
    try {
        int totalNeededAmmo = 0;
        for (int i = 0; i < _aircrafts.size(); ++i) {
            int aircraftMaxAmmo = _aircrafts[i].get_maxAmmo();
            int aircraftActualAmmo = _aircrafts[i].get_ammoAmount();
            int aircraftNeededAmmo = aircraftMaxAmmo - aircraftActualAmmo;
            totalNeededAmmo += aircraftNeededAmmo;
        }

        if (_carrierAmmo <= 0) {
            throw "There is no ammo on the ship";
        } else {
            if (_carrierAmmo < totalNeededAmmo) {
                for (int i = 0; i < _aircrafts.size(); ++i) {
                    if (_aircrafts[i].isPriority()) {
                        _aircrafts[i].refill(_aircrafts[i].get_maxAmmo());
                    } else {

                    }
            }

        }

    } catch (std::string exception) {
        std::cout << exception << std::endl;
    }
}




/*void Carrier::fill()
{
    try {
        int totalNeededAmmo = 0;
        for (int i = 0; i < _aircrafts.size(); ++i) {
            int aircraftMaxAmmo = _aircrafts[i].get_maxAmmo();
            int aircraftActualAmmo = _aircrafts[i].get_ammoAmount();
            int aircraftNeededAmmo = aircraftMaxAmmo - aircraftActualAmmo;
            totalNeededAmmo += aircraftNeededAmmo;
        }
        if (_carrierAmmo < totalNeededAmmo) {
            for (int i = 0; i < _aircrafts.size(); ++i) {
                if (_aircrafts[i].isPriority()) {
                    _aircrafts[i].refill(_aircrafts[i].get_maxAmmo());
                } else {

                }
            }
        }


    }

 */
