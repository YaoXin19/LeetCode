class Solution {
public:
  pair<int, int> extend(const std::string& s, int lo, int hi) {
    while (0<=lo && hi<s.size() && s[lo]==s[hi]) {
      lo--;
      hi++;
    }
    lo++;
    hi--;
    return { lo, hi-lo };
  }

  string longestPalindrome(string s) {
    pair<int, int> max_len{ 0, 0 }; // <begin, len>
    for (int i=1; i<s.length(); ++i) {
      pair<int, int> p1 = this->extend(s, i, i);
      if (max_len.second < p1.second)
        max_len = p1;

      pair<int, int> p2 = this->extend(s, i-1, i);
      if (max_len.second < p2.second)
        max_len = p2;
    }

    return s.substr(max_len.first, max_len.second+1);
  }
};