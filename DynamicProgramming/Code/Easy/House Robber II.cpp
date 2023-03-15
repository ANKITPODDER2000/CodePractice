class Solution {
    int recFunc(vector<int> &nums, int n) {
        if(n == 1) return nums[0];
        int a = nums[0], b = max(nums[0], nums[1]);
        for(int i = 2; i < n; i++) {
            int temp = a;
            a = b;
            b = max(temp + nums[i], b);
        }
        return b;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> nums1 = nums, nums2 = nums;
        nums1.erase(nums1.begin());
        nums2.pop_back();
        
        int ans1 = recFunc(nums1, n-1);
        int ans2 = recFunc(nums2, n-1);

        return max(ans1, ans2);
    }
};