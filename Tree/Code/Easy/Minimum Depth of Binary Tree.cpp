#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int lh = minDepth(root->left), rh = minDepth(root->right);
        return 1 + (lh == 0 ? rh : rh == 0 ? lh
                                           : min(lh, rh));
    }
};