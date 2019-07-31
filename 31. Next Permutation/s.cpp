class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    // 求下一个最大的数
    // 1 2 5 8 7 从右找到第一个升序对
    // 1 2 7 8 5 从右找到第一个比升序对中小值大的，swap
    // 1 2 7 5 8 反转

    // 1. 找到a[i]<a[i+1]
    int i = nums.size()-2;
    while (0<=i && nums[i+1]<=nums[i])
      i--;
    if (0 <= i) {
      // 2. 找到第一个a[j]>a[i],并交换
      int j = nums.size()-1;
      while (0<=j && nums[j]<=nums[i]) j--;
      if (0 <= j)
        std::swap(nums[i], nums[j]);
    }

    // 3. 反转a[i]之后的，这里隐含了i=-1
    std::reverse(nums.begin()+(i+1), nums.end());
  }
};