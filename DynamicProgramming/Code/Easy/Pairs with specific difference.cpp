class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int n, int K) {
        sort(arr, arr+n);
        int i = n-1, s = 0;
        while(i > 0) {
            if(abs(arr[i] - arr[i-1]) < K) {
                s += (arr[i] + arr[i-1]);
                i -= 2;
            }
            else i--;
        }
        return s;
    }
};