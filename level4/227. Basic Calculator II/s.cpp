class Solution {
public:
  int calculate(string s) {
    // 注意：多位数的情况

    // +-更新result
    // x/更新curr
    // 遇到-号，将其绑定到当前数字curr上
    /*
                1  *  2  -  3  /  4  +  5  *  6   -   7  *  8     +     9  /  10
    prev        0     1     2    -3     0     5      30    -7         -56      9
    prev sign   +     *     -     /     +     *       -     *           +      /
    curr        1     2(2) -3     4(0)  5     6(30)  -7     8(-56)      9     10()
    result      0     0     2     2     2     2      32     32        -24
    */

    int prev = 0;
    long long int curr = 0;
    char prev_sign = '+';
    char curr_sign = '+';
    int result = 0;

    s += "+0";

    for (int i=0; i<s.size(); ++i) {
      char temp = s[i];
      if (' ' == temp) continue;
      if ('+'==temp || '-'==temp || '*'==temp || '/'==temp) { // 更新符号
        prev_sign = temp;
      }
      else { // 计算
        prev = curr;
        curr = 0;
        int temp = s[i] - '0';
        while (0<=temp && temp<10) {
          curr = curr*10 + temp;
          temp = s[++i] - '0';
        }
        --i; // 注意

        //curr = s[i] - '0';
        if ('+' == prev_sign) {
          result += prev;
        }
        else if ('-' == prev_sign) {
          curr = -curr;
          result += prev;
        }
        else if ('*' == prev_sign) {
          curr *= prev;
        }
        else {
          curr = prev / curr;
        }
        int a = 10;
      }
    }

    return result;
  }
};