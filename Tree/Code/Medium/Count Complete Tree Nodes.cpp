class Solution {
    int recFunc1(TreeNode *node) {
        if(!node) return 0;
        return 1 + recFunc1(node->left);
    }
    int recFunc2(TreeNode *node) {
        if(!node) return 0;
        return 1 + recFunc2(node->right);
    }
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh = recFunc1(root);
        int rh = recFunc2(root);
        if(lh == rh) return (1 << lh) - 1;

        return 1 + ( countNodes(root->left) + countNodes(root->right));
    }
};