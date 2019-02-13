#include "Chef.h"

Chef::Chef(int experience) : Employees(experience)
{

}

void Chef::work()
{
    _experience++;
}

void Chef::cook(std::string mealName)
{
    for (int i = 0; i < _meals.size(); ++i) {
        if(_meals[i] = mealName) {

        }
    }
}

