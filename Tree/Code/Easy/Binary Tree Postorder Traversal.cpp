#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> ans;
    void recFunc(TreeNode *root)
    {
        if (!root)
            return;
        recFunc(root->left);
        recFunc(root->right);
        ans.push_back(root->val);
    }

public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        recFunc(root);
        return ans;
    }
};