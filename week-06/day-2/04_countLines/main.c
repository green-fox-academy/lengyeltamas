#include <stdio.h>
#include <string.h>

// Write a function that takes a filename as string,
// then returns the number of lines the file contains.
// It should return zero if it can't open the file.

int file_line_counter(char * file_name);

int main ()
{
    printf("%d",file_line_counter("../my-file.txt"));
    return 0;
}

int file_line_counter(char * file_name)
{
    FILE *my_file = fopen(file_name, "r");
    if (my_file == NULL) {
        return -1;
    }
    int result = 1;
    int ch = 0;
    while(!feof(my_file)){
        ch = fgetc(my_file);
        if (ch == '\n'){
            result++;
        }
    }
    fclose(my_file);
    return result;
}