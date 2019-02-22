#ifndef EXERCISE_3_ONLINEORDER_H
#define EXERCISE_3_ONLINEORDER_H

#include "order.h"

class OnlineOrder : public Order
{
public:
    OnlineOrder(std::vector<Dish> dishes, std::string address);
    void notEnoughIngredients() override;

private:
    std::string _address;
};

#endif //EXERCISE_3_ONLINEORDER_H