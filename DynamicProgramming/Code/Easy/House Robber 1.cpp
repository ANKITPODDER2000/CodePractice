class Solution {
    int recFunc(vector<int> &nums, int n) {
        if(n <= 0) return 0;
        cout << n << endl;
        return max(nums[n-1] + recFunc(nums, n-2) , recFunc(nums, n-1));
    }
public:
    int rob(vector<int>& nums) {
        return recFunc(nums, nums.size());
    }
};