class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int left = (n+m+1)/2;
        int right = (n+m+2)/2;

        return (solve(nums1, n, nums2, m, left, 0, 0) + solve(nums1, n, nums2, m, right, 0, 0))/2.0;
    }

    int solve(vector<int>& a, int m, vector<int>& b, int n, int k, int aStart, int bStart){
        if(m > n){
            return solve(b, n, a, m, k, bStart, aStart);
        }
        if(m == 0){
            return b[bStart + k - 1];
        }
        if(k == 1){
            return min(a[aStart], b[bStart]);
        }

        int i = min(m, k/2);
        int j = min(n, k/2);

        if(a[aStart+i-1] > b[bStart+j-1]){
            return solve(a, m, b, n-j, k-j, aStart, bStart+j);
        }
        else{
            return solve(a, m-i, b, n, k-i, aStart+i, bStart);
        }
    }
};
