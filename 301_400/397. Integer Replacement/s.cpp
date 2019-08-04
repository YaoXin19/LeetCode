class Solution {
public:
    void bt(unsigned int  n, unsigned int path, vector<unsigned int>& paths) {
        if (n == 1) {
            paths.push_back(path);
            return;
        }
        if (n < 1)
            return;
        if (n%2 == 0) { // 偶数
            bt(n/2, path+1, paths);
        } else { // 奇数
            bt(n+1, path+1, paths);            
            bt(n-1, path+1, paths);            
        }
    }
    
    int integerReplacement(int n) {
        vector<unsigned int> paths;
        bt(n, 0, paths);
        return *std::min_element(paths.begin(), paths.end());
    }
};