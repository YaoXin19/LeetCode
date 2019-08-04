class Solution {
public:
    // lower_bound 找到替换，否则添加
    // [10,9,2,5,3,7,101,18]
    // 10 添加
    // 9 替换
    // 2 替换
    // 2 5 添加
    // 2 3 替换
    // 2 3 7 添加
    // 2 3 7 101 添加
    // 2 3 7 18 替换

    int lengthOfLIS(vector<int>& nums) {
        vector<int> res; // 最长递增序列，不要求连续
        for(int i=0; i<nums.size(); i++) {
            //最小末尾序列中寻找比nums[i]大的最小数, 二分查找O(logN)
            auto iter = std::lower_bound(res.begin(), res.end(), nums[i]);

            if(iter==res.end()) res.push_back(nums[i]); //未找到则添加
            else *iter = nums[i]; //找到则替换
        }
        return res.size();
    }
};