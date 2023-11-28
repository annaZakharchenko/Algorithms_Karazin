#pragma once
using namespace std;

struct ttree
{
    int info;
    ttree* left;
    ttree* right;
};

typedef ttree* ptree;

ptree createTree();
void preOrder(ptree root);
void inOrder(ptree root);
void postOrder(ptree root);
int getValue();
int countNumOfValues(ptree root, int value);
void deleteTree(ptree root);
