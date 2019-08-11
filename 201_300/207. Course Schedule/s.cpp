class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 拓扑排序
        
        graph_ = vector<vector<int>>(numCourses);
        
        for (const auto& p:prerequisites)
            graph_[p[1]].push_back(p[0]);        // 先修课程指向后修
        
        // states: 0-unkown, 1-visiting, 2-visited
        vector<int> v(numCourses, 0);
        
        for (int i=0; i<numCourses; ++i)
            if (dfs(i, v)) return false; // 如果找到环，则为false
        
        return true;
    }
private:
    vector<vector<int>> graph_;
    bool dfs(int cur, vector<int>& v) {
        // v[cur] == 0表示没有访问过
        if (v[cur] == 1) return true; // 找到环
        if (v[cur] == 2) return false;
        
        v[cur] = 1; // 第一次到达标记位visiting
        
        for (const int t : graph_[cur])
            if (dfs(t, v)) return true; // 当前节点的所有子路径
        
        v[cur] = 2; // 返回到达标记位visited
        
        return false;
    }
};