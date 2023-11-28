#include "Header.h"
#include <iostream>

int main()
{
    int value, count;

    cout << "Enter the values for the binary tree nodes (enter 0 to finish):\n";
    ptree current = createTree();

    cout << "Pre order traversal: ";
    preOrder(current);
    cout << endl;

    cout << "In order traversal: ";
    inOrder(current);
    cout << endl;

    cout << "Post order traversal: ";
    postOrder(current);
    cout << endl;

    cout << "Enter a value to count in the tree: ";
    value = getValue();

    count = countNumOfValues(current, value);
    cout << "Number of nodes with value " << value << ": " << count << endl;

    deleteTree(current);

    return 0;
}
