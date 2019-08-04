class Solution {
public:
    bool isUgly(int num) {
        // 循环2，3，5，然后不停的除以这些质数，如果能整除就继续，最后剩余的数字是1的话就是丑陋数
        for (int i=2; i<6 && num; i++)
        while (num % i == 0)
            num /= i;
        return num == 1;
    }
};