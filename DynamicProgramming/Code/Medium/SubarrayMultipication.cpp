#define lli long long int
class Solution{
    lli max(lli a, lli b) {
        return a > b ? a : b;
    }
    lli min(lli a, lli b) {
        return a < b ? a : b;
    }
public:
	long long maxProduct(vector<int> arr, int n) {
	    lli ans = arr[0], ma = arr[0], mi = arr[0];
	    for(int i = 1; i < n; i++) {
	        if(arr[i] < 0) swap(ma, mi);
	        ma = max(arr[i], ma * arr[i]);
	        mi = min(arr[i], mi * arr[i]);
	        
	        ans = max(ans, ma);
	    }
	    return ans;
	}
};