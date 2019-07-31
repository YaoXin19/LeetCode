class Solution {
public:
    void rotateEdge(vector<vector<int>>& m, int x1, int y1, int x2, int y2) {
        for (int i=0; i<x2-x1; ++i) {
            int temp = m[x1][y1+i];
            m[x1][y1+i] = m[x2-i][y1];
            m[x2-i][y1] = m[x2][y2-i];
            m[x2][y2-i] = m[x1+i][y2];
            m[x1+i][y2] = temp;
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        int x1 = 0;
        int y1 = 0;
        int x2 = matrix.size()-1;
        int y2 = x2;
        // 从外到内，每一层对应为相交换
        while (x1 < x2)
            rotateEdge(matrix, x1++, y1++, x2--, y2--);
    }
};