#ifndef INC_03_DEVICES_PRINTER3D_H
#define INC_03_DEVICES_PRINTER3D_H
#include "Printer.h"

class Printer3D : public Printer
{
public:
    Printer3D(int sizeX, int sizeY, int sizeZ);
    std::string getSize() override;
private:
    int _sizeX;
    int _sizeY;
    int _sizeZ;
};

#endif //INC_03_DEVICES_PRINTER3D_H