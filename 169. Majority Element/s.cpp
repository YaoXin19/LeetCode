class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        std::unordered_map<int, int> m;
        int res = -1;
        for (int i=0; i<nums.size(); ++i) {
            if (m.find(nums[i]) == m.end()) {
                m[nums[i]] = 1;                
            } else {
                m[nums[i]]++;
                if (nums.size() < m[nums[i]]*2) {
                    res = nums[i];
                    break;
                }   
            }
        }
        return res;
    }
};