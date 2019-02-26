#include <stdio.h>

/*
Create a sandwich struct
It should store:
 - name
 - price (float)
 - weight (float)
Create a function which takes two parameters and returns the price of your order.
The parameters should be:
 - a sandwich struct
 - and an integer that represents how many sandwiches you want to order
*/

typedef struct {
    char* name;
    float price;
    float weight;
} sandwich_t;

float priceOfSandwich(int amount, sandwich_t ham_and_cheese);

int main()
{
    sandwich_t ham_and_cheese;
    ham_and_cheese.name = "Ham and Cheese sandwich";
    ham_and_cheese.price = 1.2;
    ham_and_cheese.weight = 0.3;

    int numberOfSandwiches = 9;

    printf("%.2f", priceOfSandwich(numberOfSandwiches, ham_and_cheese));

    return 0;
}

float priceOfSandwich(int amount, sandwich_t ham_and_cheese)
{
    return (amount * ham_and_cheese.price);
}