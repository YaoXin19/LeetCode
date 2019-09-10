class Solution {
public:
  // Question 7
  int reverse(int x) {
        int64_t xx = x; // 越界
        int flag = (0<xx) ? 1 : -1;
        xx *= flag;
        
        int64_t ans = 0; // 越界
        while (xx) {
            ans *= 10;
            int rem = xx % 10;
            xx /= 10;
            ans += rem;
        }
        
        ans *= flag;
        if (ans<-pow(2, 31) || pow(2, 31)-1<ans) // 越界
            ans = 0;
        
        return ans;
    }
    
    bool isPalindrome(int x) {
        if (0 == x) return true;
        int flag = (0<x) ? 1 : -1;
        if (-1 == flag)
            return false;

        if (x == reverse(x))
            return true;
        else
            return false;
        
    }
};