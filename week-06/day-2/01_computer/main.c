#include <stdio.h>
#include <stdint.h>

// Use the Computer struct, give values to the fields and print them out in the main!
// Use the Notebook struct, give values to the fields and print them out in the main!

struct Computer {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
};

typedef struct {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
} Notebook;

int main()
{
    struct Computer pc;

    pc.cpu_speed_GHz = 1.2;
    pc.ram_size_GB = 2;
    pc.bits = 32;


    Notebook Dell;
    Dell.cpu_speed_GHz = 2.1;
    Dell.ram_size_GB = 8;
    Dell.bits = 64;

    printf("The computer has a cpu at %.1f frequency, has %d GB memory, and has a %d bit architecture!\n", (pc.cpu_speed_GHz), (pc.ram_size_GB), (pc.bits));
    printf("The notebook has a cpu at %.1f frequency, has %d GB memory, and has a %d bit architecture!\n", (Dell.cpu_speed_GHz), (Dell.ram_size_GB), (Dell.bits));


    return 0;
}