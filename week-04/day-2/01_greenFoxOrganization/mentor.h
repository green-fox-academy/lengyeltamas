#ifndef INC_01_GREENFOXORGANIZATION_MENTOR_H
#define INC_01_GREENFOXORGANIZATION_MENTOR_H
#include "student.h"

enum Level {
    JUNIOR,
    INTERMEDIATE,
    SENIOR
};

std::string LevelToString (Level level);

class Mentor : public Person
{
public:
    Mentor();
    Mentor (std::string name, int age, Gender gender, Level level);
    void getGoal() override;
    void introduce() override;

private:
    Level _level;
};

#endif //INC_01_GREENFOXORGANIZATION_MENTOR_H