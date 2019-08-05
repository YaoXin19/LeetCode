class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // 不能用数字直接进行比较
        vector<string> strs(nums.size());
        for (int i=0; i<nums.size(); ++i)
          strs[i] = to_string(nums[i]);
        sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
          return a+b>b+a;
        });

        string ans;
        for (int i=0; i<strs.size(); ++i)
          ans += strs[i];
        
        while(ans[0]=='0' && ans.length()>1) // 去除头部的0
            ans.erase(0,1);
        
        return ans;
    }
};