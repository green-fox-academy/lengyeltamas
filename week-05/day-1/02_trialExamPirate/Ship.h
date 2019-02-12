#ifndef INC_02_TRIALEXAMPIRATE_SHIP_H
#define INC_02_TRIALEXAMPIRATE_SHIP_H
#include "Pirate.h"
#include <vector>

class Ship
{
public:
    void addPirates (Pirate pirate);
    std::vector<std::string> getPoorPirates();
    int getGolds();
    void lastDayOnTheShip();
    void prepareForBattle();
    void getPiratesFromShip();
protected:
    std::vector<Pirate> _pirates;
};

#endif //INC_02_TRIALEXAMPIRATE_SHIP_H