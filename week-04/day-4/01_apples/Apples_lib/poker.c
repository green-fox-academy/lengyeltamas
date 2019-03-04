//
// Created by Tomi on 2019. 03. 04..
//

#include "poker.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum poker_color {
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
} poker_color_t;

const char* get_poker_color(poker_color_t color)
{
    switch (color)
    {
        case CLUBS: return "Clubs";
        case DIAMONDS: return "Diamonds";
        case HEARTS: return "Hearts";
        case SPADES: return "Spades";
    }
}

typedef struct {
    int value;
    poker_color_t color;
} card_t ;

int str_to_card (const char* test_string)
{
    int result;
    char test_array[2];
    test_array [0] = test_string[0];
    test_array[1] = '\0';

    if (strcmp(test_array, "T") == 0){
        result = 10;
    } else if (strcmp(test_array, "J") == 0){
        result = 11;
    } else if (strcmp(test_array, "Q") == 0){
        result = 12;
    } else if (strcmp(test_array, "K") == 0){
        result = 13;
    } else if (strcmp(test_array, "A") == 0){
        result = 14;
    } else {
        result = atoi(test_string);
    }
    return result;
}

const char* str_to_color(const char *test_string)
{
    if (test_string[1] == 'C') {
        return get_poker_color(CLUBS);
    }
    else if (test_string[1] == 'D') {
        return get_poker_color(DIAMONDS);
    }
    else if (test_string[1] == 'H') {
        return get_poker_color(HEARTS);
    }
    else if (test_string[1] == 'S') {
        return get_poker_color(SPADES);
    }
}

/*int str_to_card_t (const char* test_string)
{
     card_t.value = str_to_card(test_string);

}*/


/*void poker_testing(char* first_player, char *card_set1, char* second_player, char *card_set2)
{
    char* set1[5];
    int counter1 = 0;
    for (char *p = strtok(card_set1, " "); p != NULL; p = strtok(NULL, " ")) {
        set1[counter1] = p;
        counter1++;
    }

    char* set2[5];
    int counter2 = 0;
    for (char *p = strtok(card_set2, " "); p != NULL; p = strtok(NULL, " ")) {
        set2[counter2] = p;
        counter2++;
    }

    char set1_card1[2];
}*/