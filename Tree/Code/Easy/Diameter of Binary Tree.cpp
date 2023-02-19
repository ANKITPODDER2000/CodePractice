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
    int ans = 0;

public:
    int recFunc(TreeNode *root)
    {
        if (!root)
            return 0;
        int lh = recFunc(root->left);
        int rh = recFunc(root->right);
        if (lh + rh > ans)
            ans = lh + rh;
        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        recFunc(root);
        return ans;
    }
};