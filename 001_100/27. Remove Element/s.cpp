class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // slow始终指向左起第一个等于val
        // fast始终指向左起第一个不等于val
        // 交换，slow指向下一个位置，fast增加
        int slow = 0, fast = 0;
        for (; slow<nums.size(); ++slow)
            if (nums[slow] == val)
                break;
        
        for (fast=slow+1; fast<nums.size(); ++fast) {
            if (nums[fast] != val)
                std::swap(nums[slow++], nums[fast]);
        }
        return slow;
    }
};