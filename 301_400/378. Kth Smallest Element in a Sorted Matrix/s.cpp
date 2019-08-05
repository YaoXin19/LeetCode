class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // 解法1：与23题相同,但需要记录每个元素的位置
        // 解法2：
        priority_queue<int> q;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                q.emplace(matrix[i][j]);
                if (q.size() > k) q.pop();
            }
        }
        return q.top();
    }
};