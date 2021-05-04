class Solution {
public:
    int findNumber (int left, int right, vector<int>& nums, int target){
        if (left == right && nums[left] != target)
            return -1;
        if (left == right - 1 && nums[left]!= target && nums[right] != target)
            return -1;
        int mid = (left + right) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] > target)
            return findNumber (left, mid-1, nums, target);
        return findNumber (mid+1, right, nums, target);
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0)
            return (vector<int>) {-1, -1};
        int pos = findNumber (0, len-1, nums, target);
        if (pos == -1)
            return (vector<int>) {-1, -1};
        int left, right;
        for (left = pos; left >=0; left--)
            if (nums[left] != target)
                break;
        for (right = pos; right < len; right++)
            if (nums[right] != target)
                break;
        return (vector<int>) {left + 1, right - 1};
    }
};

//binary search
