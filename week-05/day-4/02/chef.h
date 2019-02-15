#ifndef INC_02_CHEF_H
#define INC_02_CHEF_H

#include <map>
#include "employee.h"

class Chef : public Employee
{
public:
    Chef(std::string name, int experience = 0);

    void work() override;

    void cook(std::string mealName);

    std::string toString();

    std::string mealsToString();

private:
    std::map<std::string, int> _meals;

};

#endif //INC_02_CHEF_H