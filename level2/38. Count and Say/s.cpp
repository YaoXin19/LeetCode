class Solution {
public:
    string countAndSay(int n) {
        // 题意
        // 1
        // 11 表示之前的数是“一个一”
        // 21 表示之前的数是“两个一”
        // 1211 表示之前的数是“一个二，一个一”
        // 111221 表示之前的数是“一个一，一个二，两个一”
        // 依此类推
        
        // 求第n步的数应该是多少
         if (1 == n) return "1";
         string prev{"1"};
         for (int i=1; i<n; ++i) {
             vector<pair<char, int>> v;
             v.push_back(make_pair(prev[0], 1));
             for (int j=1; j<prev.size(); ++j) {
                if ((--v.end())->first == prev[j])
                    ++((--v.end())->second);
                 else
                     v.push_back(make_pair(prev[j], 1));
             }
             prev.clear();
             for (const auto& pair:v) {
                 prev += std::to_string(pair.second) + pair.first;
             }             
         }
        return prev;
    }
};