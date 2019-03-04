#include <string.h>
#include <stdio.h>

typedef enum
{
    MANUAL,
    AUTOMATIC,
    CVT,
    SEMI_AUTOMATIC,
    DUAL_CLUTCH
} transmission_t;

typedef struct
{
    char name[256];
    float price;
    int year;
    transmission_t transmission;
} car_t ;

typedef struct {
    car_t name [256];
    car_t price;
    car_t year;
    car_t transmission;
    char color[20];
    int length;
} something_t;


int get_older_cars_than(car_t* array, int array_length, int age);

int get_transmission_count(car_t* array, int array_length, transmission_t transmission);

const char* get_transmission_name(transmission_t transmission);

int main()
{
    car_t car1;
    strcpy(car1.name, "Volvo");
    car1.price = 35000;
    car1.year = 2014;
    car1.transmission = MANUAL;

    car_t car2;
    strcpy(car2.name, "Honda");
    car2.price = 25000;
    car2.year = 2012;
    car2.transmission = CVT;

    car_t car3;
    strcpy(car3.name, "Kia");
    car3.price = 15000;
    car3.year = 2017;
    car3.transmission = AUTOMATIC;

    something_t car4;
    car4.

    car_t car_array[3] = {car1, car2, car3};

    printf("The amount of cars older than 2 years are: %d\n",
        get_older_cars_than(car_array, (sizeof(car_array)/sizeof(car_t)), 2));

    printf("The amount of cars having manual transmission are: %d\n",
        get_transmission_count(car_array, (sizeof(car_array)/sizeof(car_t)), MANUAL));

    for (int i = 0; i < sizeof(car_array) / sizeof(car_t); ++i) {
        printf("The number %d. car's name is: %s, it's price is: %.0f, it was manufactured in %d and has %s transmission\n",
            i+1, car_array[i].name, car_array[i].price, car_array[i].year, get_transmission_name(car_array[i].transmission));
    }

    return 0;
}

int get_older_cars_than(car_t* array, int array_length, int age)
{
    int number_of_cars = 0;
    int actual_year = 2019;
    int older_than = actual_year - age;

    for (int i = 0; i < array_length; ++i) {
        if(array[i].year < older_than) {
            number_of_cars++;
        }
    }
    return number_of_cars;
}

int get_transmission_count(car_t* array, int array_length, transmission_t transmission)
{
    int number_of_transmission_type = 0;
    for (int i = 0; i < array_length; ++i) {
        if(array[i].transmission == MANUAL) {
            number_of_transmission_type++;
        }
    }
    return number_of_transmission_type;
}

const char* get_transmission_name(transmission_t transmission)
{
    switch (transmission)
    {
        case MANUAL: return "Manual";
        case AUTOMATIC: return "Automatic";
        case CVT: return "CVT";
        case SEMI_AUTOMATIC: return "Semi-automatic";
        case DUAL_CLUTCH: return "Dual Clutch";
    }
}