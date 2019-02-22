#include "dish.h"

Dish::Dish(std::string name, std::map<std::string, int> ingredients)
{
    _name = name;
    _ingredients = ingredients;
}

std::string Dish::get_name()
{
    return _name;
}

std::map<std::string, int> Dish::get_ingredients()
{
    return _ingredients;
}