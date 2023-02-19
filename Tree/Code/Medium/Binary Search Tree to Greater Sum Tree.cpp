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
    int recFunc(TreeNode *root, int val)
    {
        if (!root)
            return val;
        int rv = recFunc(root->right, val);
        root->val += rv;
        return recFunc(root->left, root->val);
    }

public:
    TreeNode *bstToGst(TreeNode *root)
    {
        recFunc(root, 0);
        return root;
    }
};