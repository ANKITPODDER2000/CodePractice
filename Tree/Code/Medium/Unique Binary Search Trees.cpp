class Solution {
public:
    int recFunc(int n, vector<int> &dp) {
        cout << n << endl;
        if(dp[n] != -1) return dp[n];
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            int n_left_node = i - 1;
            int n_right_node = n - i;
            ans += (recFunc(n_left_node, dp) * recFunc(n_right_node, dp));
        }
        return dp[n] = ans;
    }
    int numTrees(int n){
        if(n <= 1) return 1;
        vector<int> dp(n+1, -1);
        dp[0] = 1; dp[1] = 1; dp[2] = 2;
        recFunc(n, dp);
        return dp[n];
    }
};