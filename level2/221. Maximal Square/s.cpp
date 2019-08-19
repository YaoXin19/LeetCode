class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        /*
        dp表
        0 0 0 0 0 0
        0 1 0 1 0 0 
        0 1 0 1 1 1
        0 1 1 2 2 2
        0 1 0 0 1 0
        */
        // dp[i][j] = min(dp[i-1][j-1] + dp[i-1][j] + dp[i][j-1]) + 1
        //                左上角的值       左边的值      上面的值
        int h = matrix.size();
        if (0 == h) return 0;
        int w = matrix[0].size();
        int max_len = 0;
        vector<vector<int>> dp(h+1, vector<int>(w+1, 0)); // dp表的长和宽要比matrix都大1
        for (int i=1; i<=h; ++i)
            for (int j=1; j<=w; ++j) {
                if (matrix[i-1][j-1] == '1') {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                    max_len = max(max_len, dp[i][j]);
                }
            }
    
        return max_len * max_len;
    }
};