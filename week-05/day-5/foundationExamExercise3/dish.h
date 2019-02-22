#ifndef EXERCISE_3_DISH_H
#define EXERCISE_3_DISH_H
#include <string>
#include <map>

class Dish
{
public:
    Dish(std::string name, std::map<std::string, int> ingredients);

    std::string get_name();

    std::map<std::string, int> get_ingredients();

private:
    std::string _name;
    std::map<std::string, int> _ingredients;
};

#endif //EXERCISE_3_DISH_H