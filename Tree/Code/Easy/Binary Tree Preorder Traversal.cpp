#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
    vector<int> ans;
    void recFunc(TreeNode *node)
    {
        if (!node)
            return;
        ans.push_back(node->val);
        recFunc(node->left);
        recFunc(node->right);
    }

public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        recFunc(root);
        return ans;
    }
};