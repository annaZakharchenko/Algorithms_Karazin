#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* CreateNode(int data, Node* next = nullptr)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = next;
    return newNode;
}

void InsertSorted(Node*& head, int data)
{
    if (!head || head->data >= data)
    {
        Node* new_node = CreateNode(data, head);
        head = new_node;
        return;
    }

    InsertSorted(head->next, data);
}

Node* CreateList(int count)
{
    Node* head = nullptr;

    for (int i = 0; i < count; ++i)
    {
        int data;
        cout << "Enter the value " << i + 1 << ": ";
        cin >> data;
        InsertSorted(head, data);
    }

    return head;
}

void DeleteNode(Node*& head, int data)
{
    if (!head)
    {
        return;
    }
    else if (head->data == data)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    else
    {
        DeleteNode(head->next, data);
    }
}


void insertBefore(Node*& head, int data, int target)
{
    if (!head)
        return;

    if (head->data == target)
    {
        Node* new_node = CreateNode(data, head);
        head = new_node;
        return;
    }

    if (head->next && head->next->data == target)
    {
        Node* new_node = CreateNode(data, head->next);
        head->next = new_node;
        return;
    }

    insertBefore(head->next, data, target);
}

void insertAfter(Node* head, int data, int target)
{
    if (!head)
        return;

    if (head->data == target)
    {
        Node* new_node = CreateNode(data, head->next);
        head->next = new_node;
        return;
    }

    insertAfter(head->next, data, target);
}

void PrintList(Node* current)
{
    if (current)
    {
        cout << current->data << " -> ";
        PrintList(current->next);
    }
    else
    {
        cout << "nullptr" << endl;
    }
}

int main()
{
    Node* head = nullptr;
    int choice;

    do
    {
        cout << "Menu:" << endl;
        cout << "1. Create list" << endl;
        cout << "2. Delete element" << endl;
        cout << "3. Insert before element" << endl;
        cout << "4. Insert after element" << endl;
        cout << "5. Print list" << endl;
        cout << "6. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int count;
            cout << "Enter the number of elements to create: ";
            cin >> count;
            head = CreateList(count);
            PrintList(head);
            break;

        case 2:
            int deleteData;
            cout << "Enter the element to delete: ";
            cin >> deleteData;
            DeleteNode(head, deleteData);
            PrintList(head);
            break;

        case 3:
            int insertBeforeData, insertBeforeTarget;
            cout << "Enter the element to insert: ";
            cin >> insertBeforeData;
            cout << "Enter the target element before which to insert: ";
            cin >> insertBeforeTarget;
            insertBefore(head, insertBeforeData, insertBeforeTarget);
            PrintList(head);
            break;

        case 4:
            int insertAfterData, insertAfterTarget;
            cout << "Enter the element to insert: ";
            cin >> insertAfterData;
            cout << "Enter the target element after which to insert: ";
            cin >> insertAfterTarget;
            insertAfter(head, insertAfterData, insertAfterTarget);
            PrintList(head);
            break;

        case 5:
            cout << "Elements of list:" << endl;
            PrintList(head);
            break;

        case 6:
            break;

        default:
            cout << "Invalid choice. Please choose 1 - 6" << endl;
            break;
        }

    } while (choice != 6);

    return 0;
}
