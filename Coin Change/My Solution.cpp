class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;
        vector<int> dp(amount+1, -1);
        dp[0] = 0;
        for (auto coin:coins)
            if (coin <= amount)
                dp[coin] = 1;
        for (int i = 1; i <= amount; i++){
            for (auto coin:coins){
                if (i - coin <= 0)
                    continue;
                if (dp[i-coin] == -1)
                    continue;
                if ((dp[i] != -1 && dp[i-coin] + 1 < dp[i]) || dp[i] == -1)
                    dp[i] = dp[i-coin] + 1;
            }
        }
        return dp[amount];
    }
};

// O(n * k), O(n)
