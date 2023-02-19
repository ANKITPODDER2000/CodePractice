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
    vector<string> ans;
    void recFunc(TreeNode *node, string v)
    {
        if (!node)
            return;
        v = v + to_string(node->val);
        if (!node->left && !node->right)
        {
            ans.push_back(v);
            return;
        }
        recFunc(node->left, v + "->");
        recFunc(node->right, v + "->");
    }

public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        string v = "";
        recFunc(root, v);
        return ans;
    }
};