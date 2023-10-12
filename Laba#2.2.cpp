#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* formFIFO()
{
    Node* head = nullptr;
    Node* tail = nullptr;
    int number;
    cout << "Enter the number of elements: ";
    cin >> number;

    for (int i = 0; i < number; ++i)
    {
        int data;
        cout << "Enter the value " << i + 1 << ": ";
        cin >> data;
        Node* new_node = new Node;
        new_node->data = data;
        new_node->next = nullptr;
        if (!head)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
    }

    return head;
}

void printList(Node* head)
{
    Node* current = head;
    while (current)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}


int main()
{
    Node* head = formFIFO();
    cout << "Elements of list:" << endl;
    printList(head);

    return 0;
}
