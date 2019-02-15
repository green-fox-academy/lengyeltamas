#ifndef INC_02_RESTAURANT_H
#define INC_02_RESTAURANT_H

#include <vector>
#include "employee.h"

class Restaurant
{
public:
    Restaurant(std::string name, int founded);

    void guestArrived();

    void hire(Employee &employee);

    int get_founded() const;

    const std::string &get_name() const;

    std::string toString();

    std::string vectorToString();

private:
    int _founded;

    std::string _name;

    std::vector<Employee *> _employees;
public:
    const std::vector<Employee *> &get_employees() const;

};

#endif //INC_02_RESTAURANT_H