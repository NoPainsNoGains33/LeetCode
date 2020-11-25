class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return 0;
        if (len == 1)
            return nums[0];
        if (len == 2)
            return max(nums[0], nums[1]);
        int result = INT_MIN;
        vector<int> dp(len, 0);
        vector<bool> flag (len, false);
        dp[0] = nums[0];
        flag[0] = true;
        if (nums[1] > nums[0]){
            dp[1] = nums[1];
            flag[1] = true;
        }
        else{
            dp[1] = nums[0];
            flag[1] = false;
        }
        for (int i = 2; i < len; i++){
            if (flag[i-1])
                if (dp[i-1] > dp[i-2] + nums[i]){
                    dp[i] = dp[i-1];
                    flag[i] = false;
                }
                else{
                    dp[i] = dp[i-2] + nums[i];
                    flag[i] = true;
                }
            else{
                dp[i] = dp[i-2] + nums[i];
                flag[i] = true;
            }
                
        }
        return dp[len - 1];
    }
};
