#ifndef EXERCISE_3_RESTAURANT_H
#define EXERCISE_3_RESTAURANT_H
#include "order.h"

class Restaurant
{
public:
    Restaurant(std::map<std::string, int> inventory);
    Order &receiveOrder(Order &order);
    void print();
private:
    std::map<std::string, int> _inventory;
};

#endif //EXERCISE_3_RESTAURANT_H