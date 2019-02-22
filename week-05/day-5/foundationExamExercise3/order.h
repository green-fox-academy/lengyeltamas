#ifndef EXERCISE_3_ORDER_H
#define EXERCISE_3_ORDER_H
#include "dish.h"
#include <vector>

class Order
{
public:
    Order(std::vector<Dish> dishes);
    void delay();
    void deliver();
    void reject();
    std::vector<Dish> getDishes();
    virtual void notEnoughIngredients() = 0;
    void print();

private:
    int _id;
    std::string _status;
    std::vector<Dish> _dishes;
};

#endif //EXERCISE_3_ORDER_H