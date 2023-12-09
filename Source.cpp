#include "Header.h"

void Deque::pushFront(int value)
{
    dq.push_front(value);
}

void Deque::pushBack(int value)
{
    dq.push_back(value);
}

void Deque::popFront()
{
    if (!dq.empty())
    {
        dq.pop_front();
    }
    else
    {
        throw std::out_of_range("Deque is empty. Cannot pop from the front.");
    }
}

void Deque::popBack()
{
    if (!dq.empty())
    {
        dq.pop_back();
    }
    else
    {
        throw std::out_of_range("Deque is empty. Cannot pop from the back.");
    }
}

size_t Deque::size() const
{
    return dq.size();
}

void Deque::printDeque() const
{
    if (!dq.empty())
    {
        std::cout << "Deque: ";
        for (int value : dq)
        {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Deque is empty." << std::endl;
    }
}
