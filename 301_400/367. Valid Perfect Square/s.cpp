class Solution {
public:
    bool isPerfectSquare(int num) {
        // 1 = 1
        // 4 = 1 + 3
        // 9 = 1 + 3 + 5
        // 16 = 1 + 3 + 5 + 7
        // 25 = 1 + 3 + 5 + 7 + 9
        // 36 = 1 + 3 + 5 + 7 + 9 + 11
        // ....
        // so 1+3+...+(2n-1) = (2n-1 + 1)n/2 = nn
        int i = 1;
        while (true) {
            num -= (2*i - 1);
            if (num == 0)
                return true;
            else if (num < 0)
                return false;
            i++;
        }
    }
};