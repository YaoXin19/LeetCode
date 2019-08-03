class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i=0; i<nums.size(); ++i) {
      int l = i+1;
      int r = nums.size()-1;
      while (l < r) {
        int tmp = nums[i] + nums[l] + nums[r];
        if (tmp == 0) {
          res.push_back(vector<int>{nums[i], nums[l], nums[r]});
          ++l;
          while (l<nums.size() && nums[l-1]==nums[l]) ++l; // 去重，r需要去重？
        }
        else if (tmp < 0)
          ++l;
        else
          --r;
      }
      while (i<nums.size()-1 && nums[i]==nums[i+1]) ++i; // 去重
    }
    return res;
  }
};