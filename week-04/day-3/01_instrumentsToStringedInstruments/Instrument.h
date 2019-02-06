#ifndef INC_01_INSTRUMENTSTOSTRINGEDINSTRUMENTS_INSTRUMENT_H
#define INC_01_INSTRUMENTSTOSTRINGEDINSTRUMENTS_INSTRUMENT_H

#include <string>

class Instrument
{
public:
    virtual void play() = 0;

protected:
    std::string _name;
};

#endif //INC_01_INSTRUMENTSTOSTRINGEDINSTRUMENTS_INSTRUMENT_H