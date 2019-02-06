#include <iostream>
#include "Printer2D.h"
#include "Printer3D.h"
#include "Scanner.h"
#include "Copier.h"
#include <vector>

int main( int argc, char* args[] )
{
    // Create a vector that holds Printer* objects

    std::vector<Printer*> printersVector;

    // Fill the vector with 3 Printer2D, 2 Printer3D and 1 copier.

    Printer2D P2D1 (10, 10);
    Printer2D P2D2 (20, 20);
    Printer2D P2D3 (30, 30);
    Printer3D P3D1 (11, 11, 11);
    Printer3D P3D2 (22, 22, 22);
    Copier C1 (111, 111, 100);

    printersVector.push_back(&P2D1);
    printersVector.push_back(&P2D2);
    printersVector.push_back(&P2D3);
    printersVector.push_back(&P3D1);
    printersVector.push_back(&P3D2);
    printersVector.push_back(&C1);

    // Iterate through the vector and invoke print function on all of them.

    for (int i = 0; i < printersVector.size(); ++i) {
        printersVector[i]->print();
    }
    std::cout << "\n";
    // Create a vector that holds Scanner* objects

    std::vector<Scanner*> scannersVector;

    // Fill the vector with 2 Scanner and 2 Copier objects.

    Scanner S1 (1111);
    Scanner S2 (2222);
    Copier C2 (222, 222, 200);
    Copier C3 (333, 333, 300);

    scannersVector.push_back(&S1);
    scannersVector.push_back(&S2);
    scannersVector.push_back(&C2);
    scannersVector.push_back(&C3);

    // Iterate through the vector and invoke scan function on all of them

    for (int j = 0; j < scannersVector.size(); ++j) {
        scannersVector[j]->scan();
    }
    std::cout << "\n";
    // Create a Copier object and invoke copy function on it.

    Copier C4 (444, 444, 400);
    C4.copy();

}