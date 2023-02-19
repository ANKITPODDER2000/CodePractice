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
public:
    int minDiffInBST(TreeNode *root)
    {
        stack<TreeNode *> st;
        TreeNode *curr = root;
        int prevNode = -1, ans = INT_MAX;
        while (curr || !st.empty())
        {
            if (curr)
            {
                st.push(curr);
                curr = curr->left;
                continue;
            }
            curr = st.top();
            st.pop();
            if (prevNode == -1)
                prevNode = curr->val;
            else
            {
                ans = min(ans, curr->val - prevNode);
                prevNode = curr->val;
            }

            curr = curr->right;
        }
        return ans;
    }
};
