class Solution {
    bool recFunc(TreeNode *node, long long int left_bound, long long int right_bound){
        if(!node) return true;
        if(!(node->val > left_bound && node->val < right_bound))
            return false;
        return recFunc(node->left, left_bound, node->val) 
            && recFunc(node->right, node->val, right_bound);
    }
public:
    bool isValidBST(TreeNode* root) {
        return recFunc(root, -1 * 1e10, 1e10);
    }
};