#ifndef INC_02_EMPLOYEES_H
#define INC_02_EMPLOYEES_H
#include <string>

class Employees
{
public:
    Employees();
    Employees(int experience);
    virtual void work() = 0;
protected:
    std::string name;
    int _experience;
};

#endif //INC_02_EMPLOYEES_H