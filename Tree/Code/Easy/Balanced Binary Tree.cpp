#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool balanced = true;
    int getHeight(TreeNode *node)
    {
        if (!node)
            return 0;

        int lh = getHeight(node->left);
        int rh = getHeight(node->right);

        if (abs(lh - rh) > 1)
            balanced = false;
        return (1 + max(lh, rh));
    }

public:
    bool isBalanced(TreeNode *root)
    {
        getHeight(root);
        return balanced;
    }
};