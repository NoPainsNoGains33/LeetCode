// Add skipping the duplicate, just like Three Sum
// Faster than previous

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int pivot = 0; pivot < nums.size(); pivot++){
            if (pivot == 0 || nums[pivot-1] != nums[pivot])
                twoSumCloset(nums, pivot, target, diff);
                if (diff == 0)
                    return target;
        }
        return target-diff;
    }
    
    void twoSumCloset(vector<int>& nums, int pivot, int target, int& diff){
        int j = pivot + 1, right = nums.size() - 1;
        while(j < right){
            int sum = nums[pivot] + nums[j] + nums[right];
            if (abs(target - sum) < abs(diff))
                diff = target - sum;
            if (diff == 0)
                return;
            if (sum < target ){
                while(j < nums.size() - 1 && nums[j] == nums[j+1])
                    j++;
                j++;
            }
            else{
                while(right > j + 1 && nums[right] == nums[right-1])
                    right--;
                right--;
            }
        }
    }
};
