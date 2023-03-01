class Solution {
    public:
    vector<long long> printFibb(int n) {
        vector<long long> dp(n,1);
        if(n <= 2) return dp;
        for(int i = 2; i < n; i++) dp[i] = dp[i-1] + dp[i-2];
        return dp;
    }
};