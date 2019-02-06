#include "Copier.h"
#include "Printer3D.h"
#include <iostream>

Copier::Copier(int sizeX, int sizeY, int speed) : Printer2D(sizeX, sizeY), Scanner(speed)
{

}

void Copier::copy()
{
   scan();
   std::cout << " + and + ";
   print();
}