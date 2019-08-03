class Solution {
public:
    char findTheDifference(string s, string t) {
        // 异或，相同为0，不同为1
        // 与0异或，仍是本身
        char c = 0;
        for (int i=0; i<s.size(); ++i) {
            c = c ^ s[i] ^ t[i];
        }
        return c ^ t[t.size()-1];
    }
};