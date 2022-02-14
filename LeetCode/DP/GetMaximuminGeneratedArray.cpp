#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n <= 1) return n;
        vector<int> dp(n+1 , 0);
        dp[1] = 1;
        int maxVal = 1;
        for(int i = 2 ; i <= n ; i++){
            if(i%2 == 0) dp[i] = dp[i/2];
            else dp[i] = dp[i/2] + dp[(i/2)+1];
            maxVal = max(maxVal , dp[i]);
        }
        // for(auto it : dp) cout << it << " ";
        // cout << endl;
        return maxVal;
    }
};

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif


    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution obj;
        cout << obj.getMaximumGenerated(n) << endl;
    }
    return 0;
}