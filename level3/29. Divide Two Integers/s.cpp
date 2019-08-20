class Solution {
public:
  int divide(int dividend, int divisor) {
    /*
        思路：减法
        32 / 3
        (3<<0=3) < 32
        (3<<1=6) < 32
        (3<<2=12) < 32
        (3<<3=24) < 32  pow(2, 3) = 8个3
        (3<<4=48) > 32

        32-24 = 8
        8 / 3
        (3<<0=3) < 8
        (3<<1=6) < 8  pow(2, 1) = 2个3
        (3<<2=12) > 8

        8 - 6 = 2
        2 / 3
        (3<<0=3) > 2
        结束

        8个3 + 2个3 = 10个3， 所以结果为10
    */
    if (dividend == divisor) return 1;
    if (dividend == INT_MIN)
      if (divisor == -1) return INT_MAX;
      else if (divisor == 1) return INT_MIN;
    if (divisor == INT_MIN) return 0;
    if (dividend == INT_MAX && abs(divisor) == 1) return dividend*divisor;


    uint64_t long_divisor = 0;
    uint64_t long_dividend = 0;

    int sign = 1;
    if (dividend<0) {
      sign *= -1;
      int64_t temp = -1 * static_cast<int64_t>(dividend);
      long_dividend = temp;
    } else {
      long_dividend = dividend;
    }
    if (divisor < 0) {
      sign *= -1;
      long_divisor = -divisor;
    } else {
      long_divisor = divisor;
    }


    int ans = 0;
    while (long_divisor <= long_dividend) {
      uint64_t i = 0;
      uint64_t shifted = long_divisor << i++;
      while (shifted <= long_dividend) {
        shifted = long_divisor << i++;
        printf("%d\n", shifted);
      }

      long_dividend -= (shifted>>1);
      ans += std::pow(2, i-2);

    }
    return ans * sign;
  }
};
