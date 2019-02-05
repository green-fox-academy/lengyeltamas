#ifndef INC_01_GREENFOXORGANIZATION_STUDENT_H
#define INC_01_GREENFOXORGANIZATION_STUDENT_H

#include "person.h"

class Student : public Person
{
public:
    Student();
    Student(std::string name, int age, Gender gender, std::string previousOrganization);
    void getGoal() override;
    void introduce() override;
    void skipDays(int skippedDays);

private:
    std::string _previousOrganization;
    int _skippedDays;
    int _numberOfDays;

};


#endif //INC_01_GREENFOXORGANIZATION_STUDENT_H
