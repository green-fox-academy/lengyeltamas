#ifndef INC_01_INSTRUMENTSTOSTRINGEDINSTRUMENTS_STRINGEDINSTRUMENT_H
#define INC_01_INSTRUMENTSTOSTRINGEDINSTRUMENTS_STRINGEDINSTRUMENT_H
#include "Instrument.h"

class StringedInstrument : public Instrument
{
public:
    virtual std::string sound() = 0;
    void play();
protected:
    int _numberOfStrings;
};

#endif //INC_01_INSTRUMENTSTOSTRINGEDINSTRUMENTS_STRINGEDINSTRUMENT_H