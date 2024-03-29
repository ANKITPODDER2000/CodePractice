/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        if (!original || !cloned)
            return NULL;
        if (cloned->val == target->val)
            return cloned;

        TreeNode *ln = getTargetCopy(original->left, cloned->left, target);
        if (ln)
            return ln;

        return getTargetCopy(original->right, cloned->right, target);
    }
};