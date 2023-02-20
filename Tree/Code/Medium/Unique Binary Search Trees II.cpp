class Solution {
    vector<TreeNode *> recFunc(int s, int e) {
        if(s > e) return {NULL};
        if(s == e) return {new TreeNode(s)};

        vector<TreeNode *> ans;
        for(int i = s; i <= e; i++) {
            auto left_trees  = recFunc(s,i-1);
            auto right_trees = recFunc(i+1, e);
            for(auto lt : left_trees) {
                for(auto rt : right_trees) {
                    TreeNode *node = new TreeNode(i);
                    node->left = lt;
                    node->right = rt;
                    ans.push_back(node);
                }
            }
        }
        return ans;

    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return recFunc(1, n);
    }
};