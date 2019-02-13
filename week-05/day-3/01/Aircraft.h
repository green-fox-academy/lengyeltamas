#ifndef INC_01_AIRCRAFT_H
#define INC_01_AIRCRAFT_H
#include <string>

enum AircraftType {
    F16,
    F35
};

std::string aircraftToString(AircraftType aircraftType);

class Aircraft
{
public:
    Aircraft(AircraftType aircraftType);

    AircraftType get_aircraftType() const;

    int get_maxAmmo() const;

    int get_baseDamage() const;

    int get_ammoAmount() const;

    int fight();

    int refill(int fillingAmmo);

    std::string getType();

    

protected:
    AircraftType _aircraftType;
    int _maxAmmo;
    int _baseDamage;
    int _ammoAmount;
};

#endif //INC_01_AIRCRAFT_H