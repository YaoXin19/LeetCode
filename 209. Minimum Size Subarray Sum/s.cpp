class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        // 滑动窗口, 时间复杂度为O(N)
        int n = nums.size();
        int ans = std::numeric_limits<int>::max();
        int left = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            while (sum >= s) {
                ans = min(ans, i + 1 - left);
                sum -= nums[left++];
            }
        }
        return (ans != INT_MAX) ? ans : 0;
    }
};