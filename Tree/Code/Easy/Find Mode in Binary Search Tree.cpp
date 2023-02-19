#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void recFunc(TreeNode *root, map<int, int> &mp, int &m)
    {
        if (!root)
            return;
        mp[root->val] += 1;
        m = max(m, mp[root->val]);
        recFunc(root->left, mp, m);
        recFunc(root->right, mp, m);
    }

public:
    vector<int> findMode(TreeNode *root)
    {
        map<int, int> mp;
        int m = 0;
        recFunc(root, mp, m);
        vector<int> ans;
        for (auto it : mp)
        {
            if (it.second == m)
                ans.push_back(it.first);
        }
        return ans;
    }
};