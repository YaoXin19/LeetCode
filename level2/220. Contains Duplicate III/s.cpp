class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        // map会对key进行排序
        // 前开后闭区间[a, b)
        // std::map::lower_bound
        // std::map::upper_bound
        
        // nums[i]与nums[j]之间最大相差t
        // i与j之间最大相差k
        
        // 数字越界
        
        map<int64_t, int> m;
        int j = 0;
        for (int i=0; i<nums.size(); ++i) {
            if (k < i-j) m.erase(nums[j++]);
            auto low = m.lower_bound(static_cast<int64_t>(nums[i])-t); // 注意处理越界
            if (low!=m.end() && abs(low->first-nums[i])<=t) return true;
            m.emplace(nums[i], i);
        }
        return false;
    }
};