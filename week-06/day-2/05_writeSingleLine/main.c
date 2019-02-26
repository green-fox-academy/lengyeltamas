#include <stdio.h>
#include <string.h>

// Open a file called "my-file.txt"
// Write your name in it as a single line

int main ()
{
    FILE *my_file = fopen("../my-file.txt", "w");
    char* my_name = "Lengyel Tamas";
    fputs(my_name, my_file);
    
    return 0;
}