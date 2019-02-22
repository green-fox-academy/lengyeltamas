#include <iostream>
#include "order.h"
#include "onlineOrder.h"
#include "offlineOrder.h"
#include "restaurant.h"

Dish getGyros();
Dish getPizza();

int main()
{
    srand((time_t)NULL);
    std::map<std::string, int> inventory;
    inventory["ingredient1"] = 50;
    inventory["ingredient2"] = 5;

    Restaurant restaurant(inventory);

    Dish gyros = getGyros();
    Dish pizza = getPizza();

    OfflineOrder offlineOrder ({pizza, pizza, pizza, pizza, pizza, pizza, pizza}, 5);
    restaurant.receiveOrder(offlineOrder).print();

    OnlineOrder onlineOrder ({gyros}, "Szervian 20.");
    restaurant.receiveOrder(onlineOrder).print();
    return 0;
}

Dish getGyros()
{
    std::map<std::string, int> ingredients;
    ingredients["ingredient1"] = 5;
    ingredients["ingredient2"] = 1;

    Dish gyros("Gyros", ingredients);

    return gyros;
}

Dish getPizza()
{
    std::map<std::string, int> ingredients;
    ingredients["ingredient1"] = 1;
    ingredients["ingredient2"] = 10;

    Dish pizza("Pizza", ingredients);

    return pizza;
}