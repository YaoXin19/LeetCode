class Solution {
public:
  int findNthDigit(int n) {
    // 1. 找到所在数的长度范围
    //      1~9是1, 个数9, 共占位9*1=9
    //      10~99是2, 个数90, 共占位90*2=180
    //      100~999, 个数900, 共占位900*3=2700
    // 2. 找到确定的数
    // 3. 找到确定的位

    // 举例
    // 2887 = 9 * 1 + 90 * 2 + 2698 落在第3个区间
    // 2698 / 3 = 399 第三个区间的第399个数
    // 2698 % 3 = 1 第400个数的第一位

    unsigned int index = 1; // 第几个区间,区间内每个数的宽度
    unsigned int num = 9; // 每个区间多少个数
    unsigned int start = 1; // 每个区间开始的第一个数

    while (n > num * index) {
      n -= num * index;
      start += num;
      num *= 10;
      index += 1;
    }

    int target_num = start - 1 + n / index;
    int target_bit = n % index;

    std::string str;
    if (target_bit == 0) { // target_num的最后一位
      str = to_string(target_num);
    }
    else { // target_num下一个数的target_bit位
      str = to_string(target_num+1);
    }
    target_bit = (target_bit==0)?index-1:target_bit-1;

    return str[target_bit]-'0'; // 用atoi会出错
  }
};