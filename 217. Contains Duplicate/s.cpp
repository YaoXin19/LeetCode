class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        bool ans = false;
        std::unordered_set<int> hash;
        for (int i=0; i<nums.size(); ++i) {
            if (hash.find(nums[i]) == hash.end()) {
                hash.emplace(nums[i]);                
            } else {
                ans = true;
                break;                
            }
        }
        return ans;
    }
};