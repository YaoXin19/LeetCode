class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    int sum = 0;
    sort(nums.begin(), nums.end());
    int diff = std::numeric_limits<int>::max();
    for (int i=0; i<nums.size(); ++i) {
      int l = i+1;
      int r = nums.size()-1;
      while (l < r) {
        int tmp = nums[i] + nums[l] + nums[r];
        int curr_diff = std::abs(tmp-target);
        if (curr_diff < diff) {
          sum = tmp;
          diff = curr_diff;
        }
        if (tmp == target) {
          return tmp;
          while (l<nums.size() && nums[l-1]==nums[l]) ++l; // 去重
        }
        else if (tmp < target)
          ++l;
        else
          --r;
      }
      while (i<nums.size()-1 && nums[i]==nums[i+1]) ++i; // 去重
    }
    return sum;
  }
};