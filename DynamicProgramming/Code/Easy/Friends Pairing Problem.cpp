class Solution {
public:
    int countFriendsPairings(int n) { 
        long long int mod = 1e9 + 7;
        long long int val1 = 1, val2 = 1;
        if(n <= 1) return 1;
        for(int i = 2; i <= n; i++) {
            int op1 = val2;
            int op2 = ((i-1) * val1) % mod;
            val1 = (val2);
            val2 = (op1 + op2) % mod;
        }
        return val2;
    }
};  