class Solution{
    int recFunc(int A[], int n, int lastVal, vector<vector<int>> &dp) {
        if(n == 0) return 0;
        else if(dp[n][lastVal] != -1) return dp[n][lastVal];
        int val1 = INT_MIN, val2 = INT_MIN;
        if(lastVal == 0 || abs(A[n-1] - lastVal) == 1) val1 = 1 + recFunc(A, n-1, A[n-1], dp);
        val2 = recFunc(A, n-1, lastVal, dp);
        return dp[n][lastVal] = max(val1, val2);
        
    }
public:
    int longestSubsequence(int N, int A[]) {
        vector<vector<int>> dp(N+1, vector<int>(1001, -1));
        return recFunc(A, N, 0, dp);
    }
};