#include <stdio.h>

// Write a function that takes a car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level

enum car_type {VOLVO, TOYOTA, LAND_ROVER, TESLA};

struct car {
	enum car_type type;
	double km;
	double gas;
};

void printGasLevel(struct car CAR);

int main()
{
	struct car CAR1;
	CAR1.type = VOLVO;
	CAR1.km = 123000;
	CAR1.gas = 60;

	struct car CAR2;
	CAR2.type = TESLA;
	CAR2.km = 30000;

	printGasLevel(CAR1);
	printGasLevel(CAR2);

	return 0;
}

void printGasLevel(struct car CAR)
{
    if (CAR.type == TESLA) {
        printf("That's an electric car, it has no gas!");
    } else {
        printf("Amount of gas: %.1f\n", CAR.gas);
    }
}