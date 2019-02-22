#include <iostream>
#include "order.h"

Order::Order(std::vector<Dish> dishes)
{
    _dishes = dishes;
    _id = (1000 + (rand() % 9000));
    _status = "Created";
}

void Order::delay()
{
    _status = "waiting";
}

void Order::deliver()
{
    _status = "delivered";
}

void Order::reject()
{
    _status = "rejected";
}

std::vector<Dish> Order::getDishes()
{
    return _dishes;
}

void Order::print()
{
    std::cout << "Order ID: " << _id << std::endl;
    std::cout << "Status: " << _status << std::endl;
    std::cout << "Order items: " << std::endl;
    for (int i = 0; i < _dishes.size(); ++i) {
        std::cout << "\t" << _dishes[i].get_name() << std::endl;
    }
}