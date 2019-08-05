class Solution {
public:
    int nthUglyNumber(int n) {
        std::vector<int> v(n+1, 0);
        v[0] = 1;
        int i2 = 0;
        int i3 = 0;
        int i5 = 0;
        for (int j=1; j<=n; ++j) {
            int next2 = 2*v[i2];
            int next3 = 3*v[i3];
            int next5 = 5*v[i5];
            int next = std::min(next2, std::min(next3, next5));
            if (next == next2) ++i2;
            if (next == next3) ++i3;
            if (next == next5) ++i5;
            v[j] = next;
        }
        return v[n-1];
    }
};