class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int k = 0;
        for (int i=digits.size()-1; 0<=i; --i) {
            int t = digits[i] + k;
            if (i == digits.size()-1) t += 1;
            k = t / 10;
            digits[i] = t % 10;
        }
        if (k == 1)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};