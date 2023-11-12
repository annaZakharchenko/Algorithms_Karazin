#include <iostream>
#include <string>
#include "Header.h"


int main()
{
    ptree root = nullptr;

    double gradetosearch;
    double gradetodelete;

    AddStudent(root);

    cout << "Students in descending order of grades:" << std::endl;
    InOrder(root);

    cout << "Enter a grade (to delete students with that grade): ";
    cin >> gradetodelete;
    root = DeleteStudent(root, gradetodelete);

    cout << "New list of students :" << endl;
    InOrder(root);

    cout << "Enter a grade (to find students with lower grades): ";
    cin >> gradetosearch;
    cout << "List of students with grade lower than " << gradetosearch << ":" << endl;
    FindStudentWithLowerGrade(root, gradetosearch);

    delete root;
    return 0;
}
