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
    int recFunc(TreeNode *node, bool isLeftTree)
    {
        if (!node)
            return 0;
        else if (!node->left && !node->right)
            return isLeftTree ? node->val : 0;
        return recFunc(node->left, true) + recFunc(node->right, false);
    }

public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        return recFunc(root, false);
    }
};