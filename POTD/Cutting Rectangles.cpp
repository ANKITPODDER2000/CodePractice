class Solution{
public:
    vector<long long int> minimumSquares(long long int L, long long int B)
    {
        vector<long long int> v;
        long long K = __gcd(L,B);
        long long N = (L*B)/(K*K);
        
        v.push_back(N);
        v.push_back(K);
        return v;
    }
};