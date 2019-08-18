class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        unordered_map<string, function<int(int, int)>> m{
            {"+", [](int a, int b){return a+b;}},
            {"-", [](int a, int b){return a-b;}},
            {"*", [](int a, int b){return a*b;}},
            {"/", [](int a, int b){return a/b;}}
        };
        
        for (int i=0; i<tokens.size(); ++i) {
            if (m.find(tokens[i]) == m.end()) {
                s.push(atoi(tokens[i].c_str()));
            } else {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                s.push(m[tokens[i]](a, b));
            }
        }
        return s.top();
    }
};