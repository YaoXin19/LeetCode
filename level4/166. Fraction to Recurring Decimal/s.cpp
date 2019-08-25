class Solution {
public:
  string fractionToDecimal(int numerator, int denominator) {
    // abs()的时候可能会越界
    // 558898 / 999900 = 0.55(8953)
      /*
        558898
        589480
        895300
        953800
        538900
        389500
        895300
      */
    std::string ans;
    if ((numerator<0&&0<denominator) || (0<numerator&&denominator<0))
      ans += "-";

    uint64_t a = std::abs(static_cast<int64_t>(numerator));
    uint64_t b = std::abs(static_cast<int64_t>(denominator));

    ans += std::to_string(a / b);

    std::unordered_map<uint64_t, uint64_t> m;
    uint64_t remainder = a % b;
    if (remainder)
      ans += ".";
    while (remainder) {
      if (m.find(remainder) != m.end()) {
        ans.insert(m[remainder], "(");
        ans += ")";
        break;
      }

      m.emplace(remainder, ans.size());
      remainder *= 10;
      ans += std::to_string(remainder / b);
      remainder %= b;

    }

    return ans;
  }
};