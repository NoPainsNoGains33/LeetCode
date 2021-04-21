class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s == "")
            return 0;
        
        int n = s.size();
        // dp是当前长度的最长 下标代表起始点 dp_1代表长度-1的最长 dp_2代表长度-2的最长
        vector<int> dp(n, 0), dp_1(n, 0), dp_2(n, 0); 
        for (int length = 1; length <= n; length++){
            for (int left = 0; left <= n - length ; left++){
                int right = left + length - 1;
                if (left == right){
                    dp[left] = 1;
                    continue;
                }
                if (s[left] == s[right])
                    dp[left] = dp_2[left + 1] + 2;
                else
                    dp[left] = max(dp_1[left], dp_1[left + 1]);
            }
            dp.swap(dp_1);
            dp_2.swap(dp);
        }
        return dp_1[0];
    }
};
