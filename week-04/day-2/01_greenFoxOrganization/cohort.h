#ifndef INC_01_GREENFOXORGANIZATION_COHORT_H
#define INC_01_GREENFOXORGANIZATION_COHORT_H
#include <iostream>
#include <vector>
#include "student.h"
#include "mentor.h"

class Cohort : public Student, public Mentor
{
public:
    Cohort(std::string name);
    void addStudent(Student*);
    void addMentor(Mentor*);
    void info();

private:
    std::string _name;
    std::vector <Student*> _students;
    std::vector <Mentor*> _mentors;
};

#endif //INC_01_GREENFOXORGANIZATION_COHORT_H
