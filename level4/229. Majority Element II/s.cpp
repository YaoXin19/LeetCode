class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // 时间O(N), 空间O(1)
        // 求所有出现超过n/3, 所以最多有2个数，最少0个数
        // 该算法结果需要验证
        vector<int> ans;
        if (nums.size() == 0) return ans;
        
        int candidate1 = 0;
        int candidate2 = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] == candidate1)
                cnt1++;
            else if (nums[i] == candidate2)
                cnt2++;
            else if (cnt1 == 0) {
                candidate1 = nums[i];
                cnt1 = 1;
            } else if (cnt2 == 0) {
                candidate2 = nums[i];
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        
        // 验证
        cnt1 = 0;
        cnt2 = 0;
        for (int i=0; i<nums.size(); ++i) {
            if (candidate1 == nums[i]) cnt1++;
            if (candidate2 == nums[i]) cnt2++;
        }
        
        if (nums.size()/3 < cnt1) ans.push_back(candidate1);
        if (nums.size()/3<cnt2 && candidate2!=candidate1) ans.push_back(candidate2);
        return ans;
    }
};