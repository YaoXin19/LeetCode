class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        bool ans = false;
        std::unordered_map<int, int> hash;
        for (int i=0; i<nums.size(); ++i) {
            if (hash.find(nums[i])!=hash.end() && i-hash[nums[i]]<=k)
                ans = true;
            else
                hash[nums[i]] = i;
        }
        return ans;
    }
};