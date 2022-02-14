// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int CHARS = 26;

// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string str1, string str2);

// Driver program to run the case
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin>>t;
    while(t--)
    {
        string str1,str2;
        cin>>str1>>str2;
        cout << remAnagram(str1, str2);
        cout<<endl;
    }
    return 0;
}

int remAnagram(string str1, string str2){
    cout << "HI\n";
    map<char , int> mp;
    for(auto it : str1) mp[it] += 1;
    for(auto it : str2) mp[it] -= 1;
    int ans = 0;
    for(auto it : mp) ans += it.second;
    return ans;
}