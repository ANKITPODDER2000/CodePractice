// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        map<int, int> mp;
        int a , b;
        for(int i = 0 ; i < n ; i++){
            mp[arr[i]]++;
            if(mp[arr[i]] == 2) a = arr[i];
        }
        for(int i = 1 ; i <= n ; i++){
            if(mp.count(i) == 0) {
                b = i;
                break;
            }
        }
        arr[0] = a;
        arr[1] = b;
        return arr;
    }
};

// { Driver Code Starts.

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends