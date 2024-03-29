class Solution {
public:
    int firstUniqChar(string s) {
        std::vector<int> v(26, 0);
        for (auto c:s)
            ++v[c-'a'];

        for (int i=0; i<s.length(); ++i)
            if (v[s[i]-'a'] == 1)
                return i;
        return -1;
    }
};