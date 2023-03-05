class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[]) {
        vector<vector<int>> dp(N+1, vector<int>(W+1, 0));
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= W; j++) {
                int v = (wt[i-1] <= j ? (dp[i][j-wt[i-1]] + val[i-1]) : 0);
                dp[i][j] = max(v, dp[i-1][j]);
            }
        }
        return dp[N][W];
    }
};