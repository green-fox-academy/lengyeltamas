#ifndef INC_03_DEVICES_PRINTER_H
#define INC_03_DEVICES_PRINTER_H
#include <string>

class Printer
{
public:
    virtual std::string getSize() = 0;
    void print();
};


#endif //INC_03_DEVICES_PRINTER_H