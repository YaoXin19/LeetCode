class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
              // 拓扑排序
        
        graph_ = vector<vector<int>>(numCourses);
        
        for (const auto& p:prerequisites)
            graph_[p[1]].push_back(p[0]);        // 先修课程指向后修
        
        // states: 0-unkown, 1-visiting, 2-visited
        vector<int> v(numCourses, 0);
        vector<int> ans;
        
        for (int i=0; i<numCourses; ++i)
            if (dfs(i, v, ans)) return vector<int>(); // 如果找到环，则为false
        
        std::reverse(ans.begin(), ans.end());
        return ans;  
    }
private:
    vector<vector<int>> graph_;
    bool dfs(int cur, vector<int>& v, vector<int>& ans) {
        // v[cur] == 0表示没有访问过
        if (v[cur] == 1) return true; // 找到环
        if (v[cur] == 2) return false;
        
        v[cur] = 1; // 第一次到达标记位visiting
        
        for (const int t : graph_[cur])
            if (dfs(t, v, ans)) return true; // 当前节点的所有子路径
        
        v[cur] = 2; // 返回到达标记位visited
        ans.push_back(cur);
        
        return false;
    }
};
