class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        for (int i = 0; i < nums.size() && diff != 0; i++){
            int j = i + 1, k = nums.size() - 1;
            while (j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(target - sum) < abs(diff))
                    diff = target - sum;
                if (sum < target)
                    j++;
                else
                    k--;
            } 
        }
        return target-diff;
    }
};

// 无优化
