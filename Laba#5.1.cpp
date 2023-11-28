#include <iostream>
#include "Header.h"



int main()
{
    pnode head = nullptr;
    pnode tail = nullptr;

    CreateList(head, tail);

    int choice, info, new_info;
    while (true)
    {
        cout << "Menu:\n1. Display List Forward\n2. Display List Backward\n3. Insert Before\n4. Insert After\n5. Delete By Value\n6. Check Symmetry\n0. Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            DisplayList(head);
            break;
        case 2:
            DisplayReverseList(tail);
            break;
        case 3:
            cout << "Enter the value to insert before: ";
            cin >> info;
            cout << "Enter the new value: ";
            cin >> new_info;
            InsertBefore(head, info, new_info);
            break;
        case 4:
            cout << "Enter the value to insert after: ";
            cin >> info;
            cout << "Enter the new value: ";
            cin >> new_info;
            InsertAfter(head, tail, info, new_info);
            break;
        case 5:
            cout << "Enter the value to delete: ";
            cin >> info;
            DeleteByValue(head, tail, info);
            break;
        case 6:
            if (CheckSymmetry(head, tail))
                cout << "The list is symmetric." << endl;
            else
                cout << "The list is not symmetric." << endl;
            break;
        case 0:
            while (head)
            {
                pnode temp = head;
                head = head->next;
                delete temp;
            }
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
