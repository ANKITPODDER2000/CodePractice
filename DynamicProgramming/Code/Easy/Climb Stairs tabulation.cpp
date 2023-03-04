// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
#define lli unsigned long long int
using namespace std;

class Solution {
    map<lli, lli> mp;
public:
    lli climbStairs1(lli n) {
        if(n == 0) return 1;
        else if(mp.count(n) != 0) return mp[n];
        lli ans = 0;
        if(n >= 2) ans += climbStairs1(n-2);
        ans += climbStairs1(n-1);
        return mp[n] = ans;
    }
    
    lli climbStairs2(lli n) {
        vector<lli> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++) dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }

    lli climbStairs3(lli n) {
        lli val1 = 1, val2 = 1;
        for(lli i = 2; i <= n; i++) {
            lli temp = val1 + val2;
            val1 = val2;
            val2 = temp;
        }
        return val2;
    }
};

int main() {
    // Write C++ code here
    Solution *s = new Solution();
    cout << s->climbStairs1(10000) << endl; // tc : O(n) | sc O(n) | Auxiliary Space : O(n) -> Stack Space.. 
    cout << s->climbStairs2(10000) << endl; // tc : O(n) | sc O(n)
    cout << s->climbStairs3(10000) << endl; // Best optimal solution Tc O(n) | sc : O(1)
    return 0;
}