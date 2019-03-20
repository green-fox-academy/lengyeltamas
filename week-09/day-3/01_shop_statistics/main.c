#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

//In the file you can find the daily log of a shop's traffic sensor. For every hour it logs the number of incoming and outgoing customers
//The first line tells you how much hours it was working. Let's say this number is N.
//Then N lines follows. Each of them contains the time frame and 0s and 1s. 0 means a customer left the store, 1 means a customer entered the store.
//Create a function that reads the data and returns a pointer to it and the size.
//Create functions to answer the following questions:

//How many customers the shop had that day?
//What was the time with the most traffic?(Sum of incoming and outgoing customers)
//When the shop needs the most cashiers?(When was the time the most customer was in the store)
//Does it worth it to keep the shop open in the last 2 hours? It is worth it if at least 5% of the total customers was in the store at the last 2 hours.

int main()
{
    FILE* input_file_pointer = fopen("../file.txt", "r");
    if (input_file_pointer == NULL) {
        printf("File can't be opened");
    }
    char time_array[16][11];
    int in_out_amounts_in_timeslot[16][2];
    int i = 0;
    char in_out_temp[1];
    char time_stamp[11];
    int customer_enters = 0;
    int customer_left = 0;

    while(!feof(input_file_pointer)){
        fscanf(input_file_pointer, "%s %s", time_stamp, in_out_temp);
        for (int j = 0; j < 11; ++j) {
            time_array[i][j] = time_stamp[j];
        }
        char *token = strtok(in_out_temp, " ");
        while( token != NULL ) {
            int value = atoi(token);
            if (value == 0){
                customer_left++;
            } else {
                customer_enters++;
            }
            token = strtok(NULL, " ");
        }
        in_out_amounts_in_timeslot[i][0] = customer_left;
        in_out_amounts_in_timeslot[i][1] = customer_enters;
        i++;
    }
    fclose(input_file_pointer);

    printf("");

    return 0;
}