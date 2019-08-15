class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0) return;
        
        int height = board.size();
        int width = board[0].size();

        vector<vector<int>> visited(height, vector<int>(width, 0));
        
        for (int i=0; i<height; ++i) {
            if ('O' == board[i][0]) // 最左 
                bfs(board, i, 0, visited, false);
            if ('O' == board[i][width-1]) // 最右
                bfs(board, i, width-1, visited, false);
        }
        
        for (int i=0; i<width; ++i) {
            if ('O' == board[0][i]) // 最上 
                bfs(board, 0, i, visited, false);
            if ('O' == board[height-1][i]) // 最下
                bfs(board, height-1, i, visited, false);            
        }
        
        for (int i=1; i<height-1; ++i)
            for (int j=1; j<width-1; ++j) {
                if (board[i][j]=='O' && !visited[i][j])
                    bfs(board, i, j, visited, true);
            }
    }
private:
    void bfs(vector<vector<char>>& board, int x, int y, vector<vector<int>>& visited, bool flip) {
        if (x<0 || board.size()<=x || y<0 || board[0].size()<=y) return;
        if (visited[x][y]) return;
        if (board[x][y] == 'X') return;
        if (flip) board[x][y] = 'X';
        
        visited[x][y] = 1;
        bfs(board, x+1, y, visited, flip);
        bfs(board, x-1, y, visited, flip);
        bfs(board, x, y-1, visited, flip);
        bfs(board, x, y+1, visited, flip);        
    }
};