class Solution {
public:  
    void bt(const vector<int>& candidates, vector<vector<int>>& paths, vector<int> path, int next, int target) {
        if (target == 0) {
            paths.push_back(path);
            return;
        }
        
        if (next==candidates.size() || target-candidates[next]<0)
            return;
        
        int temp = next; 
        while (temp+1<candidates.size() && candidates[temp]==candidates[temp+1]) ++temp; // 去重
        
        path.push_back(candidates[next]);
        bt(candidates, paths, path, next+1, target-candidates[next]); // 与39相比，这里是next+1
        path.erase(--path.end());
        bt(candidates, paths, path, temp+1, target); // 如果当前值不要的话，与其相同的值都不要
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        bt(candidates, res, vector<int>(), 0, target);
        return res;
    }
};