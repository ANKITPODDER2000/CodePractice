#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> ans;
    void rec(vector<int>& nums , int n ,
    vector<int> temp , int s){
        if(s == n) {
            this->ans.push_back(temp);
            return;
        }
        this->rec(nums , n , temp , s+1);
        temp.push_back(nums[s]);
        this->rec(nums , n , temp , s+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        rec(nums , nums.size() , vector<int>() , 0);
        return this->ans;
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
        vector<int> arr(n);
        for(int i = 0 ; i < n ; i++) cin >> arr[i];
        Solution obj;
        auto ans = obj.subsets(arr) ;
        for(auto it : ans){
            cout << "[ ";
            for(auto i : it){
                cout << i << " ";
            }
            cout << "]\n";
        }
        cout << " --------------------------- \n";
    }
    return 0;
}