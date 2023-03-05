class Solution{
    int recFunc(vector<vector<int>> &M, int n, int m, int r, int c,
        vector<vector<int>> &visited, vector<vector<int>> &dp) {
        if(r >= n || c >= m || r < 0 || c < 0 || visited[r][c] == 1) return 0;
        if(dp[r][c] != -1) return dp[r][c];
        visited[r][c] = 1;
        int val = M[r][c] + max(
                recFunc(M, n, m, r+1, c+1, visited, dp),
                max(
                    recFunc(M, n, m, r-1, c+1, visited, dp),
                    recFunc(M, n, m, r, c+1, visited, dp)
                )
            );
        visited[r][c] = 0;
        return dp[r][c] = val;
    }
public:
    int maxGold(int n, int m, vector<vector<int>> M) {
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int maxVal = 0;
        for(int i = 0; i < n; i++) {
            maxVal = max(maxVal, recFunc(M, n, m, i, 0, visited, dp));
        }
        return maxVal;
    }
};