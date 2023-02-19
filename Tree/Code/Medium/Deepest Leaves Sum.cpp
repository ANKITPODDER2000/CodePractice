class Solution
{
public:
    int deepestLeavesSum(TreeNode *root)
    {
        if (!root)
            return false;
        queue<TreeNode *> q;
        q.push(root);
        int lastLevelSum = root->val;
        while (!q.empty())
        {
            int s = q.size();
            int temp = 0;
            while (s--)
            {
                if (q.front()->left)
                {
                    q.push(q.front()->left);
                    temp += q.front()->left->val;
                }
                if (q.front()->right)
                {
                    q.push(q.front()->right);
                    temp += q.front()->right->val;
                }
                q.pop();
            }
            if (q.empty())
                break;
            lastLevelSum = temp;
        }
        return lastLevelSum;
    }
};