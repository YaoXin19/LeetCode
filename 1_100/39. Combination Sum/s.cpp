class Solution {
public:
    
    void bt(const vector<int>& candidates, vector<vector<int>>& paths, vector<int> path, int next, int target) {
        // 不能用next == candidates.size(), 因为允许重复
        if (target == 0) {
            paths.push_back(path);
            return;
        }
        
        if (next==candidates.size() || target-candidates[next]<0)
            return;
        
        path.push_back(candidates[next]);
        bt(candidates, paths, path, next, target-candidates[next]);
        path.erase(--path.end());
        bt(candidates, paths, path, next+1, target);        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end()); // 需要排序？
        vector<vector<int>> res;
        bt(candidates, res, vector<int>(), 0, target);
        return res;
    }
};