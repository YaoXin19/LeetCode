class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 时间O(N), 空间O(1)
        int max = nums.size();
        int except = max * (max + 1) / 2;
        int actual = 0;
        for (auto num:nums)
            actual += num;
        return except - actual;
    }
};