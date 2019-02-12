#ifndef INC_02_TRIALEXAMPIRATE_PIRATE_H
#define INC_02_TRIALEXAMPIRATE_PIRATE_H
#include <string>

class Pirate
{
public:
    Pirate(std::string name, bool isCapitain, bool hasWoodenLeg);

    void work();
    void party();
    std::string toString();
    bool isCapitain() const;
    bool hasWoodenLeg() const;
    int amountOfGold() const;
    const std::string &get_name() const;
protected:
    std::string _name;
    int _amountOfGold;
    int _healthPoint;
    bool _isCapitain;
    bool _hasWoodenLeg;
};

#endif //INC_02_TRIALEXAMPIRATE_PIRATE_H