class Solution {
public:
    int maxArea(vector<int>& height) {
        // 边界：小的移动
        int res = 0;
        int left = 0, right = height.size()-1;
        while (left < right) {
            res = std::max(res, (right-left)*std::min(height[left], height[right]));
            if (height[left] < height[right]) ++left;
            else --right;
        }
        return res;
    }
};