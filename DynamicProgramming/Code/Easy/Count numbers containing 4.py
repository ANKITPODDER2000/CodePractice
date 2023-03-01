class Solution:
    def countNumberswith4(self, N):
        ans = 0
        for i in range(4, N+1):
            if '4' in str(i):
                ans += 1
        return ans
