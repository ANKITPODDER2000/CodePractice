class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> arr;
        int i = 0, j = nums.size()-1;
        while(i <= j) {
            if(abs(nums[i]) < abs(nums[j])) {
                arr.push_back(nums[j] * nums[j]);
                j--;
            }
            else {
                arr.push_back(nums[i] * nums[i]);
                i++;
            }
        }
        reverse(arr.begin(), arr.end());
        return arr;
    }
};