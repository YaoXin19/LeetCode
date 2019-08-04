class Solution {
public:
    bool isPowerOfThree(int n) {
        if (1 == n) return true;
        while (true) {
            if (n%3 != 0)
                return false;
            else {
                n /= 3;
                if (0 == n)
                    return false;
                if (1 == n)
                    return true;
            }
        }
        return true;
    }
};v