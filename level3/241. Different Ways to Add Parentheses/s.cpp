class Solution {
public:
  vector<int> diffWaysToCompute(string input) {
    // 2 * 3 - 4 * 5
    /*
        * 右边有两种情况
            2 * (3 - (4 * 5))
            2 * ((3 - 4) * 5)
        -
            2 * 3 - 4 * 5
        * 左边有两种情况
            ((2 * 3) - 4) * 5
            (2 * (3 - 4)) * 5
    */
    vector<int> ans;
    for (int i=0; i<input.size(); ++i) {
      vector<int> left;
      vector<int> right;
      if (input[i]=='+' || input[i]=='-' || input[i]=='*') {
        left = diffWaysToCompute(input.substr(0, i));
        right = diffWaysToCompute(input.substr(i+1, input.size()-i-1));
        for (auto a : left)
          for (auto b : right)
            if (input[i] == '+')
              ans.push_back(a+b);
            else if (input[i] == '-')
              ans.push_back(a-b);
            else if (input[i] == '*')
              ans.push_back(a*b);
      }
    }
    if (ans.size() == 0) // 表示没有计算符号，只是一个数字
      ans.push_back(atoi(input.c_str()));
    return ans;
  }
};