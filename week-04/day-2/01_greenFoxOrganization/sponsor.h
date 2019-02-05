#ifndef INC_01_GREENFOXORGANIZATION_SPONSOR_H
#define INC_01_GREENFOXORGANIZATION_SPONSOR_H
#include "person.h"

class Sponsor : public Person
{
public:
    Sponsor();
    Sponsor(std::string name,int age,Gender gender,std::string company);
    void introduce() override;
    void getGoal() override;
    void hire();

private:
    std::string _company;
    int _hiredStudents;
};

#endif //INC_01_GREENFOXORGANIZATION_SPONSOR_H