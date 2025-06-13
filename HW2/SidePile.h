#ifndef SIDEPILE_H
#define SIDEPILE_H

#include <stack>

class SidePile {
private:
    std::stack<int> cards;
    static const int max_size = 5;

public:
    void push(int card);
    int pop();
    int count() const;
};

#endif