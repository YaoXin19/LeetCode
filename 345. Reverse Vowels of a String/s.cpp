class Solution {
public:
    string reverseVowels(string s) {
        std::vector<std::pair<char, int>> v;
        for (int i=0; i<s.length(); ++i) {
            if (tolower(s[i])=='a' || tolower(s[i])=='e' || tolower(s[i])=='i' || tolower(s[i])=='o' || tolower(s[i])=='u') {
                v.push_back(make_pair(s[i], i));
            }
        } 
        
        int i = 0, j = v.size()-1;
        while (i < j) {
            std::swap(v[i].second, v[j].second); // 交换
            s[v[i].second] = v[i].first; // 更新
            s[v[j].second] = v[j].first; // 更新
            i++;
            j--;
        }
        
        return s;
    }
};