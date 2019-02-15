#ifndef INC_02_EMPLOYEE_H
#define INC_02_EMPLOYEE_H
#include <string>

class Employee
{
public:
    Employee(std::string name, int experience = 0);

    virtual void work() = 0;

    const std::string &get_name() const;

    int get_experience() const;

    virtual std::string toString () = 0;

protected:
    std::string _name;

    int _experience = 0;
};

#endif //INC_02_EMPLOYEE_H