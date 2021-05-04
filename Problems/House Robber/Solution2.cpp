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
        int previous = nums[0];
        int current = nums[1] > nums[0]? nums[1]:nums[0];
        int temp;
        for (int i = 2; i < len; i++){
            temp = current;
            current = previous + nums[i] > current? previous + nums[i]: current;
            previous = temp;
        }
        return current;
    }
};

//Optimize like Fibonacci to make space complexity O(1)
