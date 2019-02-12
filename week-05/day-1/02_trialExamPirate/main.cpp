#include <iostream>
#include "Ship.h"

int main()
{
    Pirate pirate1 ("Jack", true, false);
    Pirate pirate2 ("Davey", false, true);
    Pirate pirate3 ("Hook", true, true);
    Pirate pirate4 ("Chuck", false, false);

    std::cout << pirate1.toString() << std::endl;
    std::cout << pirate2.toString() << std::endl;
    std::cout << pirate3.toString() << std::endl;
    std::cout << pirate4.toString() << std::endl;

    Ship ship;
    ship.addPirates(pirate1);
    ship.addPirates(pirate2);
    ship.addPirates(pirate3);
    ship.addPirates(pirate4);

    std::cout << "The total amount of gold of the ship's pirates are: " << ship.getGolds() << std::endl;

    pirate1.work();

    ship.prepareForBattle();
    ship.lastDayOnTheShip();

    std::cout << pirate1.toString() << std::endl;
    std::cout << pirate2.toString() << std::endl;
    std::cout << pirate3.toString() << std::endl;
    std::cout << pirate4.toString() << std::endl;

    std::cout << "The total amount of gold of the ship's pirates are: " << ship.getGolds() << std::endl;

    return 0;
}