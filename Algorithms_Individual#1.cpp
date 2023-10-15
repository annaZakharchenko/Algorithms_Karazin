#include <iostream>
#include <vector>
#include "Header.h"

int main()
{
    ListNode* linkedList = createLinkedList();

    int arraySize;
    cout << "Enter the number of elements in the array: ";
    cin >> arraySize;

    vector<int> arrayElements(arraySize);
    cout << "Enter the values of array elements:\n";
    for (int i = 0; i < arraySize; i++) 
    {
        cin >> arrayElements[i];
    }

    int connectedComponents = countConnectedComponents(linkedList, arrayElements);

    cout << "Number of connected components in the array: " << connectedComponents << endl;

    while (linkedList)
    {
        ListNode* temp = linkedList;
        linkedList = linkedList->next;
        delete temp;
    }

    return 0;
}
