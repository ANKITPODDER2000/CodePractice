class Solution {
    void merge(vector<int> &arr, int s, int mid, int e) {
        int l = e-s+1;
        vector<int> a(l, 0);
        int i = 0, j = s, k = mid+1;
        while(j <= mid || k <= e) {
            if(j == mid+1) a[i] = arr[k++];
            else if(k == e+1) a[i] = arr[j++];
            else if(arr[j] < arr[k]) a[i] = arr[j++];
            else a[i] = arr[k++];
            i++;
        }

        for(i = 0, j = s; j <= e; i++, j++) arr[j] = a[i];
    }
    void mergeSort(vector<int> &arr, int s, int e) {
        if(s >= e) return;
        int mid = (s + e) / 2;
        mergeSort(arr, s, mid);
        mergeSort(arr, mid+1, e);
        merge(arr, s, mid, e);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};