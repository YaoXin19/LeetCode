class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // BFS
        
        unordered_set<string> m{wordList.begin(), wordList.end()};
        
        if (m.find(endWord) == m.end()) return 0;
        
        int len = beginWord.length();
        queue<string> q;
        q.push(beginWord);
        int step = 0;
        while (!q.empty()) {
            ++step;
            for (int size = q.size(); size > 0; size--) {
                string temp = q.front();
                q.pop();
                for (int i=0; i<len; ++i) {
                    char c = temp[i];
                    for (int j='a'; j<='z'; ++j) {
                        temp[i] = j;
                        if (temp == endWord) return step+1; // 找到
                        if (m.find(temp) == m.end()) continue; // 跳过
                        m.erase(temp);
                        q.push(temp);
                    }
                    temp[i] = c;
                }
            }
        }
        return 0;
    }
};