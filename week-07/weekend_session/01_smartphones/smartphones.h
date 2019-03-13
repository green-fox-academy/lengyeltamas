#ifndef INC_01_SMARTPHONES_SMARTPHONES_H
#define INC_01_SMARTPHONES_SMARTPHONES_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BASEPRICE 300

typedef enum {
    SMALL,
    MEDIUM,
    BIG
} screen_size_t;

typedef struct {
    char* name;
    int release_year;
    screen_size_t screen_size;
} smartphone_t;

int get_number_of_smartphones(char* input_path);

smartphone_t* get_datas_of_smartphones(char* input_path, int number_of_smartphones, smartphone_t* smartphone);

#endif //INC_01_SMARTPHONES_SMARTPHONES_H