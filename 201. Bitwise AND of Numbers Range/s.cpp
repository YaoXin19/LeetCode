class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        // usigned 采用逻辑右移，不考虑符号位
        // signed  采用算数右移，考虑符号位
        unsigned int d = std::numeric_limits<unsigned int>::max();
        while ((m&d) != (n&d))
            d <<= 1;
        
        return m&d;
    }
};