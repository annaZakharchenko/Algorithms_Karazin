#include <iostream>
#include <cctype>
#include <string>
#include "Header.h"

int main()
{
    string prefixExpression = "/*+3968";
    int index = 0;
    TreeNode* root = createExpressionTree(prefixExpression, index);

    if (root) 
    {
        cout << "Infix Expression: ";
        printInfix(root);
        cout << endl;

        int result = evaluateExpressionTree(root);
        cout << "Result: " << result << endl;
    }

    return 0;
}
