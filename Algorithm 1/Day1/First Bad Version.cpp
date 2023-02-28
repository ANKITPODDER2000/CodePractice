#define lli unsigned long long int
class Solution {
public:
    int firstBadVersion(int n) {
        if(isBadVersion(1)) return 1;
        if(!isBadVersion(n-1)) return n;
        int i = 2, j = n-1;
        while( i <= j) {
            lli mid = ((lli)i + (lli)j) / 2;
            lli res1 = isBadVersion(mid-1), 
                res2 = isBadVersion(mid), res3 = isBadVersion(mid+1);

            if(!res1 && res2) return mid;
            else if(!res2 && res3) return mid+1;

            if(!res1) i = mid+1;
            else j = mid-1;
        }
        return -1;
    }
};