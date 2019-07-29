class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 最小堆, 时间复杂度为O(logN)
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i: nums) {
            if (pq.size() < k) pq.push(i);
            else {
                if (pq.top() < i) {
                    pq.pop();
                    pq.push(i);
                }
            }
        }
        return pq.top();
    }
};