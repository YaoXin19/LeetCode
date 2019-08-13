class Solution {
public:
  // "//aaa//qq//" -> ["aaa", "qq"]
  std::vector<std::string> Split(const std::string& str, const std::string& delims) {
    std::vector<std::string> ans;
    std::size_t current, previous = 0;
    current = str.find_first_of(delims);
    while (current != std::string::npos) {
      if (current!=0 || current!=previous)
        ans.push_back(str.substr(previous, current - previous));
      previous = current + delims.length();
      current = str.find_first_of(delims, previous);
    }
    if (current!=previous)
      ans.push_back(str.substr(previous, current - previous));
    return ans;
  }

  string simplifyPath(string path) {
    // 首先要split
    // ["a", ".", "b", "..", "..", "c"]
    // 使用stack
    // ".", ""不处理
    // ".." pop
    // 其他 push
    std::vector<std::string> strs = Split(path, "/");
    stack<string> s;
    for (const auto& str:strs) {
      if ("."==str || ""==str) {
        continue;
      }
      else if (".."==str) {
        if (!s.empty()) s.pop();
        //else s.push(str);
      }
      else {
        s.push(str);
      }
    }

    string ans;
    if (s.empty())
      ans = "/";
    else {
      while (s.size()) {
        ans = "/" + s.top() + ans;
        s.pop();
      }
    }
    return ans;
  }
};