#ifndef INC_02_MANAGER_H
#define INC_02_MANAGER_H

#include "employee.h"

class Manager : public Employee
{
public:
    Manager(std::string name, int experience = 0);

    void work() override;

    void haveAMeeting();

    int get_moodLevel() const;

    std::string toString();

private:
    int _moodLevel = 400;

};

#endif //INC_02_MANAGER_H