#ifndef CAR_REGISTER_CAR_H
#define CAR_REGISTER_CAR_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum {
    manual,
    automatic,
    CVT,
    semi_automatic,
    dual_clutch
} transmission_t;

typedef struct {
    char manufacturer_name[255];
    float price_of_car;
    int year_of_manufacture;
    transmission_t transmission;
} car_t;

char* get_transmission_name (transmission_t transmission);
int get_cars_older_than(car_t car_array[], int array_length, int age);
int get_transmission_count(car_t* cars, int array_length, transmission_t transmission);

#endif //CAR_REGISTER_CAR_H