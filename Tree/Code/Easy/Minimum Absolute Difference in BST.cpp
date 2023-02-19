#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getMinimumDifference(TreeNode *root)
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