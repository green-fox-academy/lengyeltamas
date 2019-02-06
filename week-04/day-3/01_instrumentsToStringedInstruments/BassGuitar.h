#ifndef INC_01_INSTRUMENTSTOSTRINGEDINSTRUMENTS_BASSGUITAR_H
#define INC_01_INSTRUMENTSTOSTRINGEDINSTRUMENTS_BASSGUITAR_H
#include "StringedInstrument.h"

class BassGuitar : public StringedInstrument
{
public:
    BassGuitar();
    BassGuitar(int numberOfStrings);
    std::string sound();
};

#endif //INC_01_INSTRUMENTSTOSTRINGEDINSTRUMENTS_BASSGUITAR_H