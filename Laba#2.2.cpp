#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

Node* formFIFO()
{
    Node* head = nullptr;
    Node* tail = nullptr;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int data;
        cout << "Enter the value " << i + 1 << ": ";
        cin >> data;
        Node* new_node = new Node(data);
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

    while (head)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
