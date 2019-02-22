#include "restaurant.h"

Restaurant::Restaurant(std::map<std::string, int> inventory)
{
    _inventory = inventory;
}

Order &Restaurant::receiveOrder(Order &order)
{

    std::vector<Dish> dishes = order.getDishes();

    for (std::map<std::string, int>::iterator it = _inventory.begin(); it != _inventory.end() ; ++it) {
        std::string ingredientName = it->first;
        int supply = it->second;

        int totalNeccessaryAmount = 0;
        for (int i = 0; i < dishes.size(); ++i) {
            Dish dish = dishes[i];
            std::map<std::string, int> dishIngedients = dish.get_ingredients();
            int ingredientAmount = dishIngedients[ingredientName];
            totalNeccessaryAmount += ingredientAmount;
        }

        if (totalNeccessaryAmount > supply) {
            order.notEnoughIngredients();
            return order;
        }
    }

    for (std::map<std::string, int>::iterator it = _inventory.begin(); it != _inventory.end() ; ++it) {
        std::string ingredientName = it->first;

        int totalNeccessaryAmount = 0;
        for (int i = 0; i < dishes.size(); ++i) {
            Dish dish = dishes[i];
            std::map<std::string, int> dishIngredients = dish.get_ingredients();
            int ingredientAmount = dishIngredients[ingredientName];
            totalNeccessaryAmount += ingredientAmount;
        }
        _inventory[ingredientName] -= totalNeccessaryAmount;
    }
    order.deliver();
    return order;
}