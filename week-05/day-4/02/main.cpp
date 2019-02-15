#include <iostream>
#include "restaurant.h"
#include "chef.h"
#include "waiter.h"
#include "manager.h"
#include "employee.h"

int main()
{

    Restaurant risztorante("risztorante", 1213);
    Waiter waiter1("Joco", 1);
    risztorante.hire(waiter1);
    Chef chef1("Sefbacsi", 10);
    risztorante.hire(chef1);
    Manager manager1("Jack", 100);
    risztorante.hire(manager1);

    waiter1.work();
    chef1.work();
    chef1.cook("Palacsinta");
    chef1.cook("Palacsinta");
    chef1.cook("Steak");

    manager1.work();
    manager1.haveAMeeting();

   /* std::cout << chef1.toString() << std::endl;
    std::cout << waiter1.toString() << std::endl;
    std::cout << manager1.toString() << std::endl;
    std::cout << risztorante.toString() << std::endl;*/

    for (int i = 0; i < risztorante.get_employees().size(); ++i) {
        std::cout << risztorante.get_employees()[i]->toString() << std::endl;
    }

    return 0;
}