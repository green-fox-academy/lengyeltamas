//
// Created by Tomi on 2019. 01. 29..
//

#ifndef INC_05_COUNTER_COUNTER_H
#define INC_05_COUNTER_COUNTER_H


class Counter {
public:
    Counter();
    Counter(int newnum);
    int number;
    int temp;
    void add (int plusnum);
    void add();
    int get();
    void reset();

};


#endif //INC_05_COUNTER_COUNTER_H
