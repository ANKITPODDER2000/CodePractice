class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int>> stockBuySell(vector<int> A, int n){
        vector<vector<int>> ans;
        int buyIndex = 0;
        for(int i = 1; i < n; i++) {
            if(A[i] > A[i-1]) continue;
            if(i-1 != buyIndex) ans.push_back({buyIndex, i-1});
            buyIndex = i;
        }
        if(buyIndex != n-1) ans.push_back({buyIndex, n-1});
        return ans;
    }
};