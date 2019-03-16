#include "car.h"

int main()
{

    /*car_t car1;
    strcpy(car1.manufacturer_name, "Peugeot");
    car1.price_of_car = 2000;
    car1.year_of_manufacture = 2004;
    car1.transmission = manual;

    car_t car2;
    strcpy(car2.manufacturer_name, "Ford");
    car2.price_of_car = 5000;
    car2.year_of_manufacture = 2012;
    car2.transmission = automatic;

    car_t car3;
    strcpy(car3.manufacturer_name, "Skoda");
    car3.price_of_car = 6000;
    car3.year_of_manufacture = 2017;
    car3.transmission = semi_automatic;

    car_t car_array[3] = {car1, car2, car3};
*/

    car_t* car1 = create_car_instance("Peugeot", 2000, 2004, manual);
    car_t* car2 = create_car_instance("Ford", 5000, 2012, automatic);
    car_t* car3 = create_car_instance("Skoda", 6000, 2017, semi_automatic);

    car_t* car_array[3] = {car1, car2, car3};

    printf("The number of cars, older than 6 years are: %d\n", get_cars_older_than(car_array, 3, 6));
    printf("The number of cars with manual transmission are: %d\n", get_transmission_count(car_array, 3, manual));

    return 0;
}