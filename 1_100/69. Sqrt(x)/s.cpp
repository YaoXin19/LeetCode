class Solution {
public:
    int mySqrt(int x) {
        if (0==x ||  1==x) return x; // ????
        int lo = 1, hi = x;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (mid == x/mid) return mid;
            else if (mid < x/mid) lo = mid + 1;
            else hi = mid;
        }
        return hi-1; // ?????
    }
};