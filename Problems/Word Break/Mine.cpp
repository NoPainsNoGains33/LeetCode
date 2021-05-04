class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        vector<bool> dp(len, false);
        for (int i = 0; i < len; i++){
            for (int j = 0; j <= i; j++){
                if (j != i)
                    dp[i] = dp[j] && find (wordDict.begin(), wordDict.end(), s.substr(j+1, i-j)) != wordDict.end();
                else
                    dp[i] = find (wordDict.begin(), wordDict.end(), s.substr(0, i+1)) != wordDict.end();
                if (dp[i])
                    break;
            }
        }
        return dp[len-1];
    }
};
