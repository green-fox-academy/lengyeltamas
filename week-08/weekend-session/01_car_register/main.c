#include "car.h"

int main()
{
    // creating array with dynamic memory allocation
    car_t *car_array = (car_t*) calloc(3, sizeof(car_t));

    // set first instance
    car_t car1;
    strcpy(car1.manufacturer_name, "Peugeot");
    car1.price_of_car = 2000;
    car1.year_of_manufacture = 2004;
    car1.transmission = manual;
    //place the instance at the array
    car_array[0] = car1;

    // set second instance
    car_t car2;
    strcpy(car2.manufacturer_name, "Ford");
    car2.price_of_car = 5000;
    car2.year_of_manufacture = 2012;
    car2.transmission = automatic;
    //place the instance at the array
    car_array[1] = car2;

    // set third instance
    car_t car3;
    strcpy(car3.manufacturer_name, "Skoda");
    car3.price_of_car = 6000;
    car3.year_of_manufacture = 2017;
    car3.transmission = manual;
    //place the instance at the array
    car_array[2] = car3;

    printf("The number of cars, older than 6 years are: %d\n", get_cars_older_than(car_array, 3, 7));
    printf("The number of cars with manual transmission are: %d\n", get_transmission_count(car_array, 3, manual));

    return 0;
}