class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 || nums[0] != nums[1]) return nums[0];
        else if(nums[n-2] != nums[n-1]) return nums[n-1];

        int s = 1, e = n-2;
        while(s <= e) {
            int mid = (s + e) / 2;
            cout << s << " " << e << " " << mid << endl;
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
                return nums[mid];

            if(mid & 1) { // odd
                if(nums[mid-1] == nums[mid]) s = mid+1;
                else e = mid - 1;
            }
            else {
                if(nums[mid] == nums[mid+1]) s = mid+2;
                else e = mid - 1;
            }
        }

        return -1;
    }
};