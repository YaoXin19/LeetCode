class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // ransomNote可以由magazine构成，每个只能使用一次
        std::vector<int> rv(26, 0);
        std::vector<int> mv(26, 0);
        
        for (auto c:ransomNote)
            ++rv[c-'a'];
        for (auto c:magazine)
            ++mv[c-'a'];
        
        for (int i=0; i<26; ++i) {
            if (mv[i] < rv[i])
                return false;
        }
        return true;
    }
};