class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        std::unordered_map<int, int> h;
        for (int i=0; i<nums.size(); ++i)
            h.emplace(nums[i], i);
        for (int i=0; i<nums.size(); ++i) {
            if (h.find(target-nums[i])!=h.end() && i!=h[target-nums[i]]) {
                res.push_back(i);
                res.push_back(h[target-nums[i]]);
                break;
            }
        }
                
        return res;
    }
};