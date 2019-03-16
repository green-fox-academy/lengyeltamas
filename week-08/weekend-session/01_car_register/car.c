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