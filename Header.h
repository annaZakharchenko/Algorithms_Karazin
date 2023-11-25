#pragma once
#include <iostream>
#include <cctype>
#include <string>

using namespace std;

struct TreeNode
{
    char data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char val) : data(val), left(nullptr), right(nullptr) {}
};

bool isOperator(char c);
TreeNode* createExpressionTree(const string& prefix, int& index);
int evaluateExpressionTree(TreeNode* root);
void printInfix(TreeNode* root, bool isRoot = true);

