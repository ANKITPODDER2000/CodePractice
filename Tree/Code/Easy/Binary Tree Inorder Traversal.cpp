#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> ans;
    void recFunc(TreeNode *node)
    {
        if (!node)
            return;
        recFunc(node->left);
        ans.push_back(node->val);
        recFunc(node->right);
    }

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        recFunc(root);
        return ans;
    }
};