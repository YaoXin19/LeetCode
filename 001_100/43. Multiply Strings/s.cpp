class Solution {
public:
    string multiply(string num1, string num2) {
        // num1有m位，num2有n位，则最终相乘得到的应该有m+n位，最高几位可能为0
        // index1与index2相乘，其值的个位在i+j+1位，十位在i+j位
        vector<int> v(num1.length()+num2.length(), 0);
        for (int i=num1.length()-1; 0<=i; --i)
            for (int j=num2.length()-1; 0<=j; --j) {
                int mul = (num1[i]-'0')*(num2[j]-'0');
                // 更新v中的i+j和i+j+1这两位
                int sum = mul + v[i+j+1];
                v[i+j+1] = sum % 10;
                v[i+j] += sum/10;
            }
        string ans;
        for (auto num:v)
            if (!(ans.length()==0&&num==0))
                ans += to_string(num);
        ans = ans.length()==0 ? "0" : ans;
        return ans;
    }
};