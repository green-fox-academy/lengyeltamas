#ifndef INC_03_DEVICES_SCANNER_H
#define INC_03_DEVICES_SCANNER_H
#include <string>

class Scanner
{
public:
    Scanner(int speed);
    void scan();

protected:
    int _speed;
};

#endif //INC_03_DEVICES_SCANNER_H