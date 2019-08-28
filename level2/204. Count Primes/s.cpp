class Solution {
public:
  int countPrimes(int n) {
    // 求质数，不包括n
    /*
        1 2 3 4 5 6 7 8 9
        T T T F T F T F T

        -1 none
         0 false
         1 true
    */
    if (n <= 2) return 0;

    int cnt = 0;
    vector<int> v(n+1, -1);
    v[1] = 0;
    v[2] = 1;
    v[3] = 1;
    for (int i=2; i<n; ++i) {
      if (v[i] == -1)
        v[i] = 1;

      for (int j=2*i; j<n; j+=i)
        v[j] = 0;

      if (v[i] == 1)
        ++cnt;

    }
    return cnt;
  }
};