#include <iostream>
#include "car.h"
#include "station.h"
#include <vector>

int main(int argc, char* args[]) {

    station station1;

    Car car1(10, 20);
    Car car2(20, 40);
    Car car3(30, 50);
    Car car4(60, 70);
    Car car5(80, 100);

    std::vector<Car> carsVector;

    carsVector.push_back(car1);
    carsVector.push_back(car2);
    carsVector.push_back(car3);
    carsVector.push_back(car4);
    carsVector.push_back(car5);

    for (int i = 0; i < carsVector.size(); i++) {
        station1.fill(carsVector[i]);
    }

    return 0;
}
