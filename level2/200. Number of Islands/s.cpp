class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        h_ = grid.size();
        if (0 == h_) return 0;
        w_ = grid[0].size();
        int count = 0;
        for (int i=0; i<h_; ++i)
            for (int j=0; j<w_; ++j) {
                if (grid[i][j] == '1') {
                    ++count;
                    bfs(grid, i, j);
                }
            }
        
        return count;
    }
private:
    void bfs(vector<vector<char>>& grid, int x, int y) {
        if (x<0 || h_<=x || y<0 || w_<=y || grid[x][y]!='1') return;
        grid[x][y] = '2';
        bfs(grid, x-1, y);
        bfs(grid, x, y-1);
        bfs(grid, x+1, y);
        bfs(grid, x, y+1);        
    }
private:
    int h_;
    int w_;
};