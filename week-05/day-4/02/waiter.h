#ifndef INC_02_WAITER_H
#define INC_02_WAITER_H

#include "employee.h"

class Waiter : public Employee
{
public:
    Waiter(std::string name, int experience = 0);

    void work() override;

    int get_tips() const;

    std::string toString();
private:
    int _tips = 0;

};

#endif //INC_02_WAITER_H