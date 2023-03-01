class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        int s = n - k;

        reverse(nums.begin(), nums.begin()+s);
        reverse(nums.begin()+s, nums.end());
        reverse(nums.begin(), nums.end());
    }
};