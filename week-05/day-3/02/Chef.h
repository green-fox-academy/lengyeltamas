#ifndef INC_02_CHEF_H
#define INC_02_CHEF_H
#include "Employees.h"
#include <map>

class Chef : public Employees
{
public:
    Chef(int experience);
    void work() override;
    void cook(std::string mealName);
private:
    std::map<std::string, int> _meals;

};

#endif //INC_02_CHEF_H