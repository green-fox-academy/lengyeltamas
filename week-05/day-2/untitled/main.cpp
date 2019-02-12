#include <iostream>
#include "Station.h"

int main()
{
    Car car1(10,50);
    Car car2(20,50);
    Car car3(30,50);
    Car car4(40,50);
    Car car5(50,50);

    Station station1(200);

    station1.fill(car2);

    return 0;
}