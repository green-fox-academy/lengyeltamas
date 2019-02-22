#include "offlineOrder.h"

OfflineOrder::OfflineOrder(std::vector<Dish> dishes, int table)
    : Order(dishes)
{
    _table = table;
}

void OfflineOrder::notEnoughIngredients()
{
    reject();
}
