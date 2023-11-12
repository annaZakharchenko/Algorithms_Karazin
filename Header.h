#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    double grade;
};

struct ttree
{
    Student student;
    ttree* left;
    ttree* right;
};

typedef ttree* ptree;

void InsertStudent(ptree& tree, Student student);
ptree FindMinStudent(ptree tree);
ptree DeleteStudent(ptree& tree, double grade);
void InOrder(ptree tree);
void FindStudentWithLowerGrade(ptree tree, double grade);
void AddStudent(ptree& tree);

