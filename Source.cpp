#include <iostream>
#include "Header.h"

void CreateList(pnode& head, pnode& tail)
{
    int info;
    head = tail = nullptr;

    cout << "Enter values (0 to stop):" << endl;

    cin >> info;
    if (info)
    {
        head = new tnode;
        head->info = info;
        head->prev = nullptr;
    }

    cin >> info;
    pnode cur = head;
    while (info)
    {
        cur->next = new tnode;
        cur->next->prev = cur;
        cur = cur->next;
        cur->info = info;
        cin >> info;
    }

    cur->next = nullptr;
    tail = cur;
}

void DisplayList(pnode head)
{
    pnode cur = head;
    while (cur)
    {
        cout << cur->info << " ";
        cur = cur->next;
    }
    cout << endl;
}

void DisplayReverseList(pnode tail)
{
    pnode cur = tail;
    while (cur)
    {
        cout << cur->info << " ";
        cur = cur->prev;
    }
    cout << endl;
}

int InsertBefore(pnode& head, int info, int new_info)
{
    if (!head)
        return 0;

    if (head->info == info)
    {
        pnode new_node = new tnode;
        new_node->info = new_info;
        new_node->prev = nullptr;
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        return 1;
    }

    pnode cur = head;
    while (cur)
    {
        if (cur->info == info)
        {
            pnode new_node = new tnode;
            new_node->info = new_info;
            new_node->prev = cur->prev;
            new_node->next = cur;
            cur->prev->next = new_node;
            cur->prev = new_node;
            return 1;
        }
        cur = cur->next;
    }

    return 0;
}

int InsertAfter(pnode& head, pnode& tail, int info, int new_info)
{
    if (!head)
        return 0;

    pnode cur = head;
    while (cur)
    {
        if (cur->info == info)
        {
            pnode new_node = new tnode;
            new_node->info = new_info;
            new_node->next = cur->next;
            new_node->prev = cur;
            cur->next = new_node;
            if (new_node->next)
                new_node->next->prev = new_node;
            if (cur == tail)
                tail = new_node;
            return 1;
        }
        cur = cur->next;
    }

    return 0;
}

int DeleteByValue(pnode& head, pnode& tail, int info)
{
    if (!head)
    {
        return 0;
    }

    pnode cur = head;
    while (cur)
    {
        if (cur->info == info)
        {
            if (cur->prev)
            {
                cur->prev->next = cur->next;
            }
            if (cur->next)
            {
                cur->next->prev = cur->prev;
            }
            if (cur == head)
            {
                head = cur->next;
            }
            if (cur == tail)
            {
                tail = cur->prev;
            }
            delete cur;
            return 1;
        }
        cur = cur->next;
    }

    return 0;
}

bool CheckSymmetry(pnode head, pnode tail)
{
    pnode forward = head;
    pnode backward = tail;

    while (forward && backward)
    {
        if (forward->info != backward->info)
        {
            return false;
        }
        forward = forward->next;
        backward = backward->prev;
    }

    return true;
}