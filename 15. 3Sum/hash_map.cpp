class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < n && nums[i] <= 0; i++){
            if (i == 0 || nums[i-1] != nums[i])
                twoSum(nums, result, i);
        }
        return result;
    }
    void twoSum(vector<int>& nums, vector<vector<int>>& result, int pivot){
        unordered_set<int> seen;
        for (int j = pivot + 1; j < nums.size(); j++){
            int complement = -nums[pivot] - nums[j];
            // One time hash, check whether the complement existed or not
            // If existed, push the result
            if (seen.count(complement)){
                result.push_back({nums[pivot], complement, nums[j]});
                while (j + 1 < nums.size() && nums[j] == nums[j+1])
                    j++;
            }
            seen.insert(nums[j]);
        }
    }
};
