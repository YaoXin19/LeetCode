class NumArray {
public:
    NumArray(vector<int>& nums) {
        nums_ = nums;
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        for (int k=i; k<=j; ++k)
            sum += nums_[k];
        return sum;
    }
private:
    vector<int> nums_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */