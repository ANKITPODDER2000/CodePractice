class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode *> q;
        if(!root) return false;
        q.push(root);
        bool isLastNode = false;
        while(!q.empty()) {
            TreeNode *t = q.front();
            q.pop();
            if(isLastNode && t->left) return false;
            if(t->left) q.push(t->left);
            else isLastNode = true;

            if(isLastNode && t->right) return false;
            if(t->right) q.push(t->right);
            else isLastNode = true;
        }
        return true;
    }
};