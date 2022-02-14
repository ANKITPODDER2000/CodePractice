#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1 , 0);
        for(int i = 1 ; i <= n ; i++){
            if(i&1) dp[i] = dp[i-1]+1;
            else dp[i] = dp[i/2];
        }
        return dp;
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
        Solution ob;
        vector<int> ans = ob.countBits(n);
        for(auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}