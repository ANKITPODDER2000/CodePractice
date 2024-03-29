class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int a = nums[0], b = max(nums[0], nums[1]);
        for(int i = 2; i < n; i++) {
            int temp = a;
            a = b;
            b = max(temp + nums[i], b);
        }
        return b;
    }
};