#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* createNode(int data, Node* next = nullptr)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = next;
    return newNode;
}

void formLIFO_2(Node*& head, int data)
{
    Node* new_node = createNode(data, head);
    head = new_node;
}

Node* formLIFO_1()
{
    Node* head = nullptr;
    int number;
    cout << "Enter the number of elements: ";
    cin >> number;

    for (int i = 0; i < number; ++i)
    {
        int data;
        cout << "Enter the value " << i + 1 << ": ";
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
    cout << "Elements of list:" << endl;
    printList(head);

    return 0;
}
