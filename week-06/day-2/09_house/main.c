#include <stdio.h>

/*
Create a struct that represents a House
It should store:
 - The address of the house
 - The price in EUR
 - The number of rooms
 - The area of the house in square meters
The market price of the houses is 400 EUR / square meters
Create a function that takes a pointer to a house and decides if it's worth to buy
(if the price is lower than the calculated price from it's area)
Create a function that takes an array of houses (and it's length), and counts the
houses that are worth to buy.
*/

typedef struct{
    char* address;
    int price;
    int number_of_rooms;
    int area;
} house_t;

house_t create_house (char* _address, int _price, int _number_of_rooms, int _area);

int worth_to_buy(house_t *house);

void houses_worth_buying(house_t *array, int length);

int main()
{
    house_t house1 = create_house("kossuth str 10.", 40100, 3, 100);
    house_t house2 = create_house("dozsa str 100.", 40000, 3, 100);
    house_t house3 = create_house("arany janos str 43.", 50000, 2, 50);
    house_t house4 = create_house("bessenyei str 13.", 30000, 4, 150);

    house_t array_of_houses[4];
    int length_of_array = sizeof(array_of_houses) / sizeof(*array_of_houses);
    array_of_houses[0] = house1;
    array_of_houses[1] = house2;
    array_of_houses[2] = house3;
    array_of_houses[3] = house4;

   // printf("%d\n", worth_to_buy(&house1));

    houses_worth_buying(array_of_houses, length_of_array);

    return 0;
}

house_t create_house (char* _address, int _price, int _number_of_rooms, int _area)
{
    house_t house;
    house.address = _address;
    house.price = _price;
    house.number_of_rooms = _number_of_rooms;
    house.area = _area;
    return house;
}

int worth_to_buy(house_t *house)
{
    int result = 0;
    if((house->price / house-> area) < 400) {
        result = 1;
    }
    return result;
}

void houses_worth_buying(house_t *array, int length)
{
    int counter = 0;
    for (int i = 0; i < length; ++i) {
        if (worth_to_buy(&array[i]) == 1) {
            counter ++;
            printf("House nr.%d worth buying!\n", i);
        }
    }
    printf("%d houses worth buying", counter);
}