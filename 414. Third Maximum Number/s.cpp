class Solution {
public:
    int thirdMax(vector<int>& nums) 
    {
        // 优先级队列不能处理重复问题
        // map时间复杂度不满足需求
        long first = -2147483649;
        long second = -2147483649;
        long third = -2147483649;
        for (int i=0; i<nums.size(); i++)
        {
            if (nums.at(i) > first)
            {
                third = second;
                second = first;
                first = nums.at(i);
            }
            else if (nums.at(i)>second && nums.at(i)<first)
            {
                third = second;
                second = nums.at(i);
            }
            else if (nums.at(i)>third && nums.at(i)<second)
            {
                third = nums.at(i);
            }
        }
        return third==-2147483649?first:third;
    }
};