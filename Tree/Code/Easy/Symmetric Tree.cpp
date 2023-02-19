#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool recFunc(TreeNode *r1, TreeNode *r2)
    {
        if (!r1 && !r2)
            return true;
        else if ((!r1 || !r2) || (r1->val != r2->val))
            return false;
        return recFunc(r1->left, r2->right) && recFunc(r1->right, r2->left);
    }

public:
    bool isSymmetric(TreeNode *root)
    {
        return recFunc(root->left, root->right);
    }
};