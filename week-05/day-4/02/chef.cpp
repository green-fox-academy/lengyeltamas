#include "chef.h"

Chef::Chef(std::string name, int experience) : Employee(name, experience)
{
}

void Chef::work()
{
    _experience++;
}

void Chef::cook(std::string mealName)
{
    _meals[mealName]++;
}



std::string Chef::toString()
{
    return "Hello, I'm " + _name +
           " a chef, with " + std::to_string(_experience) +
           " experience points, and I've already cooked:\n" + mealsToString();
}

std::string Chef::mealsToString()
{
    std::string result;

    for (std::map<std::string, int>::iterator it = _meals.begin(); it != _meals.end(); ++it) {
        result.append(it->first + " " + std::to_string(it->second) + " times,\n");
    }
    return result;
}
