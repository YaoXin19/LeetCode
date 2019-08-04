class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int> res;
        // 把nums[i]交换到以nums[i]-1为下标的位置上
        // [4,3,2,7,8,2,3,1]
        // [1,2,3,4,x,x,7,8]
        // x就是所求值
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] != nums[nums[i] - 1]) {
				swap(nums[i], nums[nums[i] - 1]);
				--i;
			}
		}

		for (int i = 0; i < nums.size(); ++i)
			if (nums[i] != i + 1)
				res.push_back(i + 1);
		return res;
	}
};
