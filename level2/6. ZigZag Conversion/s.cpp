class Solution {
public:
  string convert(string s, const int numRows) {
    if (1 == numRows) return s;
    std::vector<string> rows(numRows);
    bool up = false;
    int row_index = 0;
    for (int i=0; i<s.size(); ++i) {
      rows[row_index] += s[i];
      if (up) --row_index;
      else ++row_index;

      if (row_index == -1) {
        up = false;
        row_index = 1;
      }
      else if (row_index == numRows) {
        up = true;
        row_index = numRows-2;
      }
    }

    string ans;
    for (const auto& row: rows)
      ans += row;
    return ans;
  }
};