class Solution {
    int $maxPathSum = INT_MIN;
    int recFunc(TreeNode *node) {
        if(!node) return 0;
        int leftTreeMaxSum = recFunc(node->left);
        if(leftTreeMaxSum < 0) leftTreeMaxSum = 0;

        int rightTreeMaxSum = recFunc(node->right);
        if(rightTreeMaxSum < 0) rightTreeMaxSum = 0;

        int s = node->val + leftTreeMaxSum + rightTreeMaxSum;
        $maxPathSum = max($maxPathSum, s);
        return node->val + max(leftTreeMaxSum , rightTreeMaxSum);
    }
public:
    int maxPathSum(TreeNode* root) {
        recFunc(root);
        return $maxPathSum;
    }
};