class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        bool needToRev = false;
        while (!q.empty())
        {
            vector<int> temp;
            int s = q.size();
            while (s--)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                temp.push_back(node->val);
            }

            if (needToRev)
                reverse(temp.begin(), temp.end());
            needToRev = !needToRev;
            ans.push_back(temp);
        }
        return ans;
    }
};