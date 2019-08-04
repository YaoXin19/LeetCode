class Solution {
public:
    string getHint(string secret, string guess) {
        // A指有多少位是对的，数字和位置必须相同
        // B指有多少位是错的, 数字相等，但位置不同
        int a = 0, b = 0;
        vector<int> s_v(10, 0); // 统计secret中，除与guess相等的，0~9分别出现了多少次 
        vector<int> g_v(10, 0);
        
        for (int i=0; i<secret.size(); ++i) {
            char c1 = secret[i]; char c2 = guess[i];
            if (c1 == c2) {
                ++a;
            } else {
                ++s_v[c1-'0'];
                ++g_v[c2-'0'];
            }
        }
        
        // 计算b
        for (int i=0; i<s_v.size(); ++i)
            b += min(s_v[i], g_v[i]);
        
        return to_string(a) + 'A' + to_string(b) + 'B';
    }
};