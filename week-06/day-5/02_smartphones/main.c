#include <stdio.h>

/* Create a smartphone register application
 * Read the content of smartphones.txt and store the informations in a structure called "smartphone:
 * - the name of the gadget (which is shorter than 256 characters) (Don't bother with the underscore('_') character,
 *   it's the part of the name)
 * - the year of the release (e.g. 2016)
 * - the type of the screen size (as a custom type, see below)
 *
 * In the file the size is given in cm but you should store the screen size type in an enumeration ("screen_size"),
 * the valid types are:
 *  - BIG -> (>= 15 cm)
 *  - MEDIUM -> (>= 12 cm)
 *  - SMALL -> (< 12 cm)
 *
 * The smartphones should be stored in an array.
 *
 * Implement the following functions:
 * - get_oldest_phone()
 *    - it should return the name of oldest device
 *    - it is up to you how your function declaration looks like (return type and arguments)
 * - get_screen_size_count()
 *    - it returns the count of phones which has "screen_size" size
 *    - it is up to you how your function declaration looks like (return type and arguments)
 *
 * Your main function should invoke these functions and print the following:
 * The ..... is the oldest device in the database
 * There are .... phones with BIG (>= 15 cm) screen size
 * There are .... phones with SMALL (< 12 cm) screen size
 *
 *
 * Additionally, you need to create a new file(prices.txt) that looks like this:
 * <NAME> <PRICE>
 * <NAME> <PRICE>
 * .
 * .
 * .
 *
 * To calculate the price use the following method. The base price of every phone is 300$.
 * If the size is SMALL, that adds 0$ to the value
 * If the size is MEDIUM, that adds 100$ to the value
 * If the size is BIG, that doubles the base price.
 *
 * The price also depends on the age. For every year that passed since its release,
 * the phone loses 50$ but the maximum value that it can lose because of the age is 250$
 */

typedef enum
{
    SMALL,
    MEDIUM,
    BIG
} screen_size_t;

typedef struct
{
    char name[256];
    int year_released;
    screen_size_t screen_size;
} smartphone_t;

void read_file_to_struct(char* input_file, smartphone_t *smartphone, int array_length);

int count_input_file_lines (char* file_path);

int main()
{
    smartphone_t smartphones[count_input_file_lines("../phones.txt")];
    //printf("%d", sizeof(smartphones)/ sizeof(smartphone_t));
    for (int i = 0; i < sizeof(smartphones)/sizeof(smartphone_t); ++i) {
        printf("The number %d. smartphones name is : %s, it's release date is: %d, anf it's size is: %d\n", i+1, smartphones[i].name, smartphones[i].year_released, smartphones[i].screen_size);
    }
    printf("%s", smartphones[2].name);

    return 0;
}

void read_file_to_struct(char* input_file, smartphone_t *smartphone, int array_length)
{
    FILE *my_file = fopen(input_file, "r");
    if (input_file == NULL) {
        printf("Can't open file!");
    }
    int size;
    int i = 0;
    while(fscanf(my_file, "%s %d %d", smartphone[i].name, &smartphone[i].year_released, &size)){
        if (i > array_length) {
            break;
        } else {
            if (size < 12) {
                smartphone[i].screen_size = SMALL;
                i++;
            } else if (size >= 12 && size < 15){
                smartphone[i].screen_size = MEDIUM;
                i++;
            } else if (size >= 15) {
                smartphone[i].screen_size = BIG;
                i++;
            }
        }
    }
    fclose(my_file);
}

int count_input_file_lines (char* file_path)
{
    FILE *my_file = fopen(file_path, "r");
    if(my_file == NULL){
        return 0;
    }
    int result = 1;
    int ch = 0;
    while(!feof(my_file)){
        ch = fgetc(my_file);
        if(ch == '\n'){
            result++;
        }
    }
    fclose(my_file);
    return result;
}