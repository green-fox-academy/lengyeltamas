#include <stdio.h>
#include <string.h>

int main ()
{
    // Open a file called "my-file.txt"
    FILE *my_file = fopen("../my-file.txt", "w");
    char* my_name = "Lengyel Tamas";
    // Write your name in it as a single line
    fputs(my_name, my_file);
    return 0;
}