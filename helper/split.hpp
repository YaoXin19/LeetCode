#include <vector>
#include <string>

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