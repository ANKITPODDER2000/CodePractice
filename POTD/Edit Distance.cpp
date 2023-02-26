/*
3 operations are possible,
  1. Insert Char
  2. Delete Char
  3. Replace Char

  F(i, j) = min(F(i-1, j), F(i, j-1), F(i-1, j-1)) + 1 # Recursive Equition...
*/
class Solution {
    int recFunc(string s1, string s2, int pos1, int pos2) {
        if(pos1 == 0) return pos2;
        else if(pos2 == 0) return pos1;

        if(s1[pos1-1] == s2[pos2-1]) return recFunc(s1,s2, pos1-1, pos2-1);

        return min(
            recFunc(s1, s2, pos1, pos2-1) + 1,
            min(
                recFunc(s1, s2, pos1-1, pos2) + 1,
                recFunc(s1, s2, pos1-1, pos2-1) + 1
            )
        );

    }
public:
    int minDistance(string word1, string word2) {
        // return recFunc(word1, word2, word1.length(), word2.length());
        int l1 = word1.length()+1, l2 = word2.length()+1;
        vector<vector<int>> dp(l1, vector<int> (l2, 0));
        for(int i = 1; i < l1; i++) dp[i][0] = i;
        for(int i = 1; i < l2; i++) dp[0][i] = i;
        for(int i = 1; i <l1; i++) {
            for(int j = 1; j < l2; j++) {
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(dp[i][j-1]+1, min(dp[i-1][j]+1, dp[i-1][j-1]+1));
            }
        }
        return dp[l1-1][l2-1];
    }
};