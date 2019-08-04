class Solution {
public:
    int removeDuplicates(vector<int>& nums) {  
        // i始终指向某个值第一次出现的位置
        // j始终指向i指向值的下一个值第一次出现的位置
        // i的下一个位置与j交换，j增加
        if (nums.empty()) return 0;
        
        int i=0, j=0;
        while (j<nums.size()) {
            if (nums[i] == nums[j]) j++;
            else std::swap(nums[++i], nums[j++]); 
        }
        
        return i+1;
    }
};