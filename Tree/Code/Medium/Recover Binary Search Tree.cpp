class Solution {
    TreeNode *t1 = NULL, *t2 = NULL, *prev_node = NULL;
    void recFunc(TreeNode *node) {
        if(!node) return ;
        recFunc(node->left);
        if(!prev_node) prev_node = node;
        else{
            if(node->val < prev_node->val) {
                if(t2) t2 = node;
                else {
                    t1 = prev_node;
                    t2 = node;
                }
            }
            prev_node = node;
        }
        recFunc(node->right);
    }
public:
    void recoverTree(TreeNode* root) {
        recFunc(root);
        int v = t1->val;
        t1->val = t2->val;
        t2->val = v;
    }
};