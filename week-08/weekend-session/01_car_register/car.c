#include "car.h"

char* get_transmission_name (transmission_t transmission)
{
    switch (transmission)
    {
        case manual: return "Manual";
        case automatic: return "automatic";
        case CVT: return "CVT";
        case semi_automatic: return "Semi-Automatic";
        case dual_clutch: return "Dual-clutch";
    }
}

car_t* create_car_instance (char* manufacturer, float price, int year, transmission_t transm)
{
    unsigned short manufacturer_name_size = (unsigned short)strlen(manufacturer);
    car_t *car = (car_t*)calloc(3, sizeof(car_t));
    car->manufacturer_name = realloc(car->manufacturer_name, manufacturer_name_size);
    strcpy(car->manufacturer_name, manufacturer);
    car->price_of_car = price;
    car->year_of_manufacture = year;
    car->transmission = transm;
    return car;
}

int get_cars_older_than(car_t car_array[], int array_length, int age)
{
    int result = 0;
    for (int i = 0; i < array_length; ++i) {
        if(car_array[i].year_of_manufacture < 2019 - age) {
            result++;
        }
    }
    return result;
}

int get_transmission_count(car_t* cars, int array_length, transmission_t transmission) {
    int result = 0;
    for (int i = 0; i < array_length; ++i) {
        if(cars[i].transmission == transmission){
            result++;
        }
    }
    return result;
}