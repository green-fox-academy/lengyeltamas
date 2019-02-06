#ifndef INC_03_DEVICES_PRINTER2D_H
#define INC_03_DEVICES_PRINTER2D_H
#include "Printer.h"

class Printer2D : public Printer
{
public:
    Printer2D(int sizeX, int sizeY  );
    std::string getSize() override;

protected:
    int _sizeX;
    int _sizeY;
};

#endif //INC_03_DEVICES_PRINTER2D_H