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
    bool recFunc(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;
        targetSum -= root->val;
        if (!root->left && !root->right && targetSum == 0)
            return true;
        return recFunc(root->left, targetSum) || recFunc(root->right, targetSum);
    }

public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        return recFunc(root, targetSum);
    }
};