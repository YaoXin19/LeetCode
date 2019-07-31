class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res(m+n, 0);
        int i = 0, j = 0;
        int k = 0;
        while (i<m && j<n)
            res[k++] = nums1[i]<nums2[j] ? nums1[i++] : nums2[j++];
        
        while (i<m)
            res[k++] = nums1[i++];
        
        while (j<n)
            res[k++] = nums2[j++];
        
        nums1 = res;
    }
};