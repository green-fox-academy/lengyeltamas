#ifndef INC_01_INSTRUMENTSTOSTRINGEDINSTRUMENTS_ELECTRICGUITAR_H
#define INC_01_INSTRUMENTSTOSTRINGEDINSTRUMENTS_ELECTRICGUITAR_H
#include "StringedInstrument.h"

class ElectricGuitar : public StringedInstrument
{
public:
    ElectricGuitar();
    ElectricGuitar(int numberOfStrings);
    std::string sound();
};

#endif //INC_01_INSTRUMENTSTOSTRINGEDINSTRUMENTS_ELECTRICGUITAR_H