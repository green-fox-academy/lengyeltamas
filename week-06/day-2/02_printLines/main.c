#include <stdio.h>
#include <string.h>

// Write a program that opens a file called "my-file.txt", then prints
// each line from the file.
// You will have to create the file, for that you may use C-programming, although it is not mandatory

int main ()
{
    FILE *write_file = fopen("my-file.txt", "w");
    for (int i = 0; i < 10; ++i) {
        char write_line[10] = "new line\n";
        fputs (write_line, write_file);
    }
    fclose(write_file);

    FILE *open_file = fopen("my-file.txt", "r");
    if(open_file == NULL) {
        printf("Failed to open!");
    }

    char read_line[11];
    while(fgets(read_line, sizeof(read_line), open_file) != NULL){
        printf("%s", read_line);
    }
    fclose(open_file);
    return 0;
}