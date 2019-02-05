#ifndef INC_06_COUNTER_H
#define INC_06_COUNTER_H


class Counter
{
public:
    Counter();
    Counter(int newNum);
    void add (int plusNum);
    void add();
    void reset();
    int get() const;
private:
    int baseNum;
    int resetNum;
};


#endif //INC_06_COUNTER_H
