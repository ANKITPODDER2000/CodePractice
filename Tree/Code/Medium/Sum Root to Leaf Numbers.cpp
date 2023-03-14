class Solution {
    int ans = 0;
    void recFunc(TreeNode *root, int val) {
        if(!root) return;
        val = (val * 10) + root->val;
        if(!root->left && !root->right) {
            ans += val;
            return;
        }
        recFunc(root->left, val);
        recFunc(root->right, val);
    }
public:
    int sumNumbers(TreeNode* root) {
        recFunc(root, 0);
        return ans;
    }
};