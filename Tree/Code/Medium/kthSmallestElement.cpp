class Solution {
    int val = INT_MIN;
    void recFunc(TreeNode *node, int &k) {
        if(!node || k <= 0) return;
        recFunc(node->left, k);
        k--;
        if(k == 0) val = node->val;
        recFunc(node->right, k);
    }
public:
    int kthSmallest(TreeNode* node, int k) {
        recFunc(node, k);
        return val;
    }
};