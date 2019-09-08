class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int n = s.size();
        int i = 0, j = 0;
        std::unordered_set<char> set;
        while (j<n) {
            if (set.find(s[j]) == set.end()) {
                set.insert(s[j++]);
                res = std::max(res, j-i);
            } else {
                set.erase(s[i++]);
            }
        }
        return res;
    }
};