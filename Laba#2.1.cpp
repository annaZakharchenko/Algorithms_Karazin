#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

void formLIFO_2(Node*& head, int data)
{
    Node* new_node = new Node(data);
    new_node->next = head;
    head = new_node;
}


Node* formLIFO_1()
{
    Node* head = nullptr;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int data;
        cout << "Enter the value" << i + 1 << ": ";
        cin >> data;
        formLIFO_2(head, data);
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
    Node* head = formLIFO_1();
    cout << "elements of list:" << endl;
    printList(head);

    while (head)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
