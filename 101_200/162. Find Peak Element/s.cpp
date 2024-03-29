class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // mid和mid+1比较
        // 如果升序，左半边全部抛弃
        // 如果降序，右半边全部抛弃
        int low = 0;
        int high = nums.size()-1; // 确保mid+1存在

        while(low < high) {
            int mid = (low + high)>>1;
            if(nums[mid] > nums[mid+1]) high = mid;
            else low = mid+1;
        }
        return low;
    }
};