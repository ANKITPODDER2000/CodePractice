#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n == 0) return 1;
        int ans = 0;
        if(n >= 2) ans += climbStairs(n-2);
        ans += climbStairs(n-1);
        return ans;
    }
};

int main(){
    Solution *s = new Solution();
    cout << "climbStairs(45) << " << s->climbStairs(45) << endl;
    return 0;
}
