#ifndef INC_01_ANIMAL_H
#define INC_01_ANIMAL_H
#include <string>

class Animal
{
public:
    void heal();
    bool isAdoptable();
    std::string toString();
protected:
    std::string _name;
    bool _isHealthy;
    int _healCost;
};

#endif //INC_01_ANIMAL_H