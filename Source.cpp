#include "Header.h"
#include <iostream>

ptree createTree()
{
    int info;
    cin >> info;
    if (info == 0)
    {
        return nullptr;
    }
    ptree tree = new ttree;
    tree->info = info;
    tree->left = createTree();
    tree->right = createTree();
    return tree;
}

void preOrder(ptree root)
{
    if (root)
    {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(ptree root)
{
    if (root)
    {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(ptree root)
{
    if (root)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}

int getValue()
{
    int value;
    cin >> value;
    return value;
}

int countNumOfValues(ptree root, int value)
{
    int count = 0;
    if (!root)
    {
        return 0;
    }

    if (root->info == value)
    {
        count++;
    }

    count += countNumOfValues(root->left, value);
    count += countNumOfValues(root->right, value);

    return count;
}

void deleteTree(ptree root)
{
    if (root)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}