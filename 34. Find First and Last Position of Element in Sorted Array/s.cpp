class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // 时间O(logN), 需要用二分
        vector<int> res{-1, -1};
        int lo = 0, hi = nums.size();
        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            if (nums[mid] == target) {
                res[0] = mid;
                while (0<res[0] && nums[res[0]-1] == target) --res[0]; // 注意边界条件
                res[1] = mid;
                while (res[1]<nums.size()-1 && nums[res[1]+1] == target) ++res[1]; // 注意边界条件
                break;
            } else if (nums[mid] < target) {
                lo = mid+1;
            } else {
                hi = mid;
            }
        }
        return res;
    }
};