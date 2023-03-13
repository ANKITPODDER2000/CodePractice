
#define lli long long int
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        lli ans = 0, l = 0, r = n-1, lmax = 0, rmax = 0;
        while(l <= r) {
            if(arr[l] < arr[r]) {
                if(arr[l] >= lmax) lmax = arr[l];
                else ans += (lmax - arr[l]);
                l++;
            }
            else {
                if(arr[r] >= rmax) rmax = arr[r];
                else ans += (rmax - arr[r]);
                r--;
            }
        }
        return ans;
    }
};