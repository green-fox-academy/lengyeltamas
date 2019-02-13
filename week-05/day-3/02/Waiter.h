#ifndef INC_02_WAITER_H
#define INC_02_WAITER_H
#include "Employees.h"

class Waiter : public Employees
{
Waiter(int experience);
void work() override;

private:
    int _tips;
};

#endif //INC_02_WAITER_H