// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
#define lli unsigned long long int
using namespace std;

class Solution {
    map<lli, lli> mp;
public:
    lli climbStairs(lli n) {
        if(n == 0) return 1;
        else if(mp.count(n) != 0) return mp[n];
        lli ans = 0;
        if(n >= 2) ans += climbStairs(n-2);
        ans += climbStairs(n-1);
        return mp[n] = ans;
    }
};

int main() {
    // Write C++ code here
    Solution *s = new Solution();
    cout << s->climbStairs(10000) << endl;
    return 0;
}