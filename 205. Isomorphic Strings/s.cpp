class Solution {
public:
    bool isIsomorphic(string s, string t) {
        bool ans = true;
        std::unordered_map<char, char> m;
        for (int i=0; i<s.size(); ++i) {
            if (m.find(s[i]) == m.end()) {
                m.emplace(s[i], t[i]);
            } else {
                if (m[s[i]] != t[i]) {
                    ans = false;
                    break;
                }
            }
        }
        if (ans) {
            m.clear();
            for (int i=0; i<t.size(); ++i) {
                if (m.find(t[i]) == m.end()) {
                    m.emplace(t[i], s[i]);
                } else {
                    if (m[t[i]] != s[i]) {
                        ans = false;
                        break;
                    }
                }
            }            
        }
        
        return ans;
    }
};