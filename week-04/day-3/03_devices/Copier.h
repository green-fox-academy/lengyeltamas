#ifndef INC_03_DEVICES_COPIER_H
#define INC_03_DEVICES_COPIER_H
#include <string>
#include "Printer2D.h"
#include "Scanner.h"

class Copier : public Printer2D, public Scanner
{
public:
    Copier(int sizeX, int sizeY, int speed);
    void copy();
};

#endif //INC_03_DEVICES_COPIER_H