class Solution {
public:
    void bt(const string& s, int next, int& total) {
        if (next == s.size()) {
            ++total;
            return;            
        }
        
        if ('0' == s[next])
            return;
        else {
            bt(s, next+1, total);
            if (1 < s.size()-next) {
                int n = atoi(s.substr(next, 2).c_str());
                if (0<n && n<27)
                    bt(s, next+2, total);                            
            }
        }
    }
    
    int numDecodings(string s) {
        // 有重复，使用bt加map实现
        int total = 0;
        bt(s, 0, total);
        return total;
    }
};