#include <iostream>
#include <string>
#include "Header.h"

void InsertStudent(ptree& tree, Student student)
{
    if (tree == nullptr)
    {
        tree = new ttree;
        tree->student = student;
        tree->left = tree->right = nullptr;
    }
    else if (student.grade > tree->student.grade)
    {
        InsertStudent(tree->right, student);
    }
    else
    {
        InsertStudent(tree->left, student);
    }
}

ptree FindMinStudent(ptree tree)
{
    while (tree->left != nullptr)
    {
        tree = tree->left;
    }
    return tree;
}

ptree DeleteStudent(ptree& tree, double grade)
{
    if (tree == nullptr)
    {
        return tree;
    }

    if (grade > tree->student.grade)
    {
        tree->right = DeleteStudent(tree->right, grade);
    }
    else if (grade < tree->student.grade)
    {
        tree->left = DeleteStudent(tree->left, grade);
    }
    else
    {
        if (tree->left == nullptr)
        {
            ptree temp = tree->right;
            delete tree;
            return temp;
        }
        else if (tree->right == nullptr)
        {
            ptree temp = tree->left;
            delete tree;
            return temp;
        }

        ptree temp = FindMinStudent(tree->right);
        tree->student = temp->student;
        tree->right = DeleteStudent(tree->right, temp->student.grade);
    }
    return tree;
}


void InOrder(ptree tree)
{
    if (tree)
    {
        InOrder(tree->right);
        cout << "Name: " << tree->student.name << endl;
        cout << "Grade: " << tree->student.grade << endl;
        InOrder(tree->left);
    }
}

void FindStudentWithLowerGrade(ptree tree, double grade)
{
    if (tree)
    {
        FindStudentWithLowerGrade(tree->left, grade);
        if (tree->student.grade < grade)
        {
            cout << "Name: " << tree->student.name << endl;
            cout << "Grade: " << tree->student.grade << endl;
        }
        FindStudentWithLowerGrade(tree->right, grade);
    }
}

void AddStudent(ptree& tree)
{

    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    for (int i = 0; i < numStudents; i++)
    {
        string name;
        double grade;

        cout << "Enter name: ";
        cin >> name;

        cout << "Enter grade: ";
        cin >> grade;

        Student newStudent = { name, grade };
        InsertStudent(tree, newStudent);
    }
}
