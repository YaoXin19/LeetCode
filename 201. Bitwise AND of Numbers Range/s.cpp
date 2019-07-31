class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        // 题意:m到n中的所有数相与的结果
        // 结论：取最高位相同的部分，剩余最低位全为0
        // usigned 采用逻辑右移，不考虑符号位
        // signed  采用算数右移，考虑符号位
        unsigned int d = std::numeric_limits<unsigned int>::max();
        while ((m&d) != (n&d))
            d <<= 1;
        
        return m&d;
    }
};