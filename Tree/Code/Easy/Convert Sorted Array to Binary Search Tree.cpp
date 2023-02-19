#include <bits/stdc++.h>
using namespace std;

class Solution
{
    TreeNode *recFunc(vector<int> nums, int l, int r)
    {
        if (l > r)
            return NULL;
        int ind = l + ((r - l) / 2);
        TreeNode *ptr = new TreeNode(nums[ind]);
        ptr->left = recFunc(nums, l, ind - 1);
        ptr->right = recFunc(nums, ind + 1, r);
        return ptr;
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return recFunc(nums, 0, nums.size() - 1);
    }
};