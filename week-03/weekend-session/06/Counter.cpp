#include <iostream>
#include "Counter.h"
Counter::Counter()
{
    baseNum = 0;
    resetNum = baseNum;
}

Counter::Counter(int newNum)
{
   baseNum = newNum;
   resetNum = baseNum;
}

void Counter::add(int plusNum)
{
    baseNum = baseNum + plusNum;
}

void Counter::add()
{
    baseNum++;
}

void Counter::reset()
{
    baseNum = resetNum;
}

int Counter::get() const
{
    return baseNum;
}