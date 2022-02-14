#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool recFunc(int n , bool isAliceMove){
        if(n <= 1){
            if(isAliceMove) return false;
            return true;
        }
        for(int i = 1 ; i < n ; i++){
            if(n%i == 0){
                bool v = recFunc(n-i , !isAliceMove);
                if((isAliceMove && v) || (!isAliceMove && !v) ) return v;
            }
        }
        if(isAliceMove) return false;
        return true;
    }
public:
    bool divisorGame(int n) {
        // return recFunc(n , true);
        vector<pair<bool , bool>> dp(n+1 , {false , false});
        dp[1] = make_pair(false , false);
        for(int i=2 ; i <= n ; i++){
            for(int j = 1 ; j < i ; j++){
                if(i % j == 0 && !dp[i-j].second){
                    dp[i].first = true;
                    // continue;
                }
                if(i % j == 0 && !dp[i-j].first){
                    dp[i].second = true;
                    // continue;
                }
            }
        }
        // for(auto it : dp) cout << "( " << it.first << " , " << it.second << " ) ";
        // cout<<endl;
        return dp[n].first;
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
        cout << obj.divisorGame(n) << endl;
    }
    return 0;
}