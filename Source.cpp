#include <iostream>
#include <cctype>
#include <string>
#include "Header.h"


bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

TreeNode* createExpressionTree(const string& prefix, int& index)
{
    char currentChar = prefix[index];
    if (isOperator(currentChar))
    {
        TreeNode* node = new TreeNode(currentChar);
        index++;
        node->left = createExpressionTree(prefix, index);
        node->right = createExpressionTree(prefix, index);
        return node;
    }
    else if (isdigit(currentChar))
    {
        TreeNode* node = new TreeNode(currentChar);
        index++;
        return node;
    }
    else
    {
        cout << "Invalid prefix expression." << endl;
        return nullptr;
    }
}

int evaluateExpressionTree(TreeNode* root)
{
    if (root->left == nullptr && root->right == nullptr)
    {
        return root->data - '0';
    }

    int leftValue = evaluateExpressionTree(root->left);
    int rightValue = evaluateExpressionTree(root->right);

    switch (root->data)
    {
    case '+':
        return leftValue + rightValue;
    case '-':
        return leftValue - rightValue;
    case '*':
        return leftValue * rightValue;
    case '/':
        return leftValue / rightValue;
    }

    return 0;
}

void printInfix(TreeNode* root, bool isRoot = true)
{
    if (root)
    {
        bool needParentheses = isOperator(root->data) && !isRoot;

        if (needParentheses)
        {
            cout << "(";
        }

        printInfix(root->left, false);
        cout << root->data;
        printInfix(root->right, false);

        if (needParentheses)
        {
            cout << ")";
        }
    }
}