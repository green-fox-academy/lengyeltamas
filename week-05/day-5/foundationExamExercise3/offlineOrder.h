#ifndef EXERCISE_3_OFFLINEORDER_H
#define EXERCISE_3_OFFLINEORDER_H
#include "order.h"

class OfflineOrder : public Order
{
public:
    OfflineOrder(std::vector<Dish> dishes, int table);
    void notEnoughIngredients() override;

private:
    int _table;
};

#endif //EXERCISE_3_OFFLINEORDER_H