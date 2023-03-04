// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
#define lli unsigned long long int
using namespace std;

class Solution {
    bool recFunc(string s, string t, int a, int b) {
        if(a == 0) return true;
        else if(b == 0) return false;
        
        if(s[a-1] == t[b-1]) return recFunc(s, t, a-1, b-1);
        return recFunc(s, t, a, b-1);
    }
public:
    bool isSubsequence1(string s, string t) {
        return recFunc(s, t, s.length(), t.length());
    }
    
    bool isSubsequence2(string s, string t) {
        int n1 = s.length(), n2 = t.length();
        if(n1 > n2) return false;
        for(int i = 0, j = 0; i < n2; i++) {
            if(t[i] == s[j]) j++;
            if(j == n1) return true;
        }
        return false;
    }
};

int main() {
    // Write C++ code here
    Solution *s = new Solution();
    cout << s->isSubsequence1("abc", "abc") << endl;
    cout << s->isSubsequence2("abc", "abc") << endl;
    
    cout << s->isSubsequence1("abc", "axbic") << endl;
    cout << s->isSubsequence2("abc", "axbic") << endl;
    
    cout << s->isSubsequence1("abc", "axbiklm") << endl;
    cout << s->isSubsequence2("abc", "axbiklm") << endl;
    return 0;
}