#include <iostream>
#include "Aircraft.h"

int main()
{
    Aircraft joe(F16);
    std::cout << "\nThe first aircraft's type are: " << aircraftToString(joe.get_aircraftType()) <<std::endl;
    Aircraft jack(F35);
    std::cout << "\nThe second aircraft's type are: " << aircraftToString(jack.get_aircraftType()) <<std::endl;

    std::cout << "\nThe remaining ammo after filling the first aircraft is: " <<joe.refill(20) << "\n" << "The first aircraft's ammo amount is: " << joe.get_ammoAmount() << std::endl;
    std::cout << "\nThe remaining ammo after filling the second aircraft is: " << jack.refill(20) << "\n" << "The second aircraft's ammo amount is: " << jack.get_ammoAmount() << std::endl;

    std::cout << "\nThe first aircraft's type are:  " <<joe.getType() << std::endl;
    std::cout << "\nThe second aircraft's type are: " <<jack.getType() << std::endl;

    std::cout << "\n" << joe.getStatus() << std::endl;
    std::cout << "\n" << jack.getStatus() << std::endl;


    std::cout << joe.priorityToString() << std::endl;
    std::cout << jack.priorityToString() << std::endl;

    return 0;
}