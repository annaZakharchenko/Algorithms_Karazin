#include <iostream>
#include <vector>
#include "Header.h"

ListNode* createLinkedList()
{
    int numOfList;
    cout << "Enter the number of elements in the linked list: ";
    cin >> numOfList;

    ListNode* head = nullptr;
    ListNode* current = nullptr;

    for (int i = 0; i < numOfList; i++)
    {
        int val;
        cout << "Enter the value of element " << i + 1 << ": ";
        cin >> val;
        if (!head)
        {
            head = new ListNode(val);
            current = head;
        }
        else
        {
            current->next = new ListNode(val);
            current = current->next;
        }
    }

    return head;
}

bool contains(const vector<int>& vals, int target)
{
    for (int i = 0; i < vals.size(); i++)
    {
        if (vals[i] == target)
        {
            return true;
        }
    }
    return false;
}

int countConnectedComponents(ListNode* head, vector<int>& vals)
{
    int components = 0;
    bool isConnected = false;

    while (head)
    {
        if (contains(vals, head->value))
        {
            isConnected = true;
        }
        else
        {
            if (isConnected)
            {
                components++;
                isConnected = false;
            }
        }
        head = head->next;
    }

    if (isConnected)
    {
        components++;
    }

    return components;
}
