class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s == "")
            return 0;
        
        int n = s.size();
        vector<vector<int>> dp (n, vector<int> (n));
        for (int length = 1; length <= n; length++){
            for (int left = 0; left <= n - length ; left++){
                int right = left + length - 1;
                if (left == right){
                    dp[left][right] = 1;
                    continue;
                }
                if (s[left] == s[right])
                    dp[left][right] = dp[left + 1][right - 1] + 2;
                else
                    dp[left][right] = max(dp[left][right - 1], dp[left + 1][right]);
            }
        }
        return dp[0][n - 1];
    }
};
