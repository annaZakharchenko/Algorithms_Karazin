#pragma once
#include <iostream>
#include <deque>

class Deque
{
private:
    std::deque<int> dq;

public:
    void pushFront(int value);
    void pushBack(int value);
    void popFront();
    void popBack();
    size_t size() const;
    void printDeque() const;
};
