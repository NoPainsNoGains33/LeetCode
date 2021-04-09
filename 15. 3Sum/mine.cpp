class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2)
            return {};
        vector<vector<int>> result;
        // Sort the array first in asending order
        sort(nums.begin(), nums.end());
        // Set the pivot
        int pivot = 0;
        while (pivot < n-2){
            int left = pivot + 1;
            int right = n - 1;
            int sum = -nums[pivot];
            // Two Sum II with pointer:
            while (left < right){
                if (nums[left] + nums[right] < sum){
                    left++;
                }
                else if (nums[left] + nums[right] > sum){
                    right--;
                } 
                // Process the equal situation
                else{
                    result.push_back({nums[pivot], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left+1])
                        left++;
                    while (right > left && nums[right] == nums[right-1])
                        right--;
                    left++, right--;
                }
            }
            // Find next pivot: not a duplicate number
            while (pivot < n-2 && nums[pivot] == nums[pivot+1])
                pivot++;
            pivot++;
        }
        return result;
    }
};
