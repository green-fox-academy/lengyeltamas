//
// Created by Tomi on 2019. 01. 29..
//
#include <iostream>
#include "Counter.h"

Counter::Counter() {
number = 0;
temp = number;
}

Counter::Counter(int newnum)
{
    number = newnum;
    temp = number;
}

void Counter::add(int plusnum)
{
    number = number + plusnum;
}

void Counter::add()
{
    number += 1;
}

int Counter::get()
{
    return number;
}

void Counter::reset()
{
    number = temp;
}