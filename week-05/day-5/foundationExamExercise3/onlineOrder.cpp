#include "onlineOrder.h"

OnlineOrder::OnlineOrder(std::vector<Dish> dishes, std::string address) :
        Order(dishes)
{
    _address = address;
}

void OnlineOrder::notEnoughIngredients()
{
    delay();
}