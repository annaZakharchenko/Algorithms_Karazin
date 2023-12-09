#include "Header.h"
#include <iostream>
#include <deque>

int main()
{
    Deque myDeque;

    int numElements;
    std::cout << "Enter the number of elements for the deque: ";
    std::cin >> numElements;

    std::cout << "Enter the elements for the deque:\n";
    for (int i = 0; i < numElements; ++i)
    {
        int element;
        std::cin >> element;
        myDeque.pushBack(element);
    }

    myDeque.printDeque();

    int frontElement;
    std::cout << "Enter an element to push to the front: ";
    std::cin >> frontElement;
    myDeque.pushFront(frontElement);

    int backElement;
    std::cout << "Enter an element to push to the back: ";
    std::cin >> backElement;
    myDeque.pushBack(backElement);

    myDeque.printDeque();

    std::cout << "Size: " << myDeque.size() << std::endl;

    myDeque.popFront();
    myDeque.printDeque();

    myDeque.popBack();
    myDeque.printDeque();

    return 0;
}
