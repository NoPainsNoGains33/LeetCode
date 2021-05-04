class Solution:
    """
    @param nums: an array of integer
    @param target: an integer
    @return: an integer
    """
    def twoSum5(self, nums, target):
        # write your code here
        if not nums:
            return 0

        nums = sorted(nums)
        left, right = 0, len(nums) - 1
        result = 0
        while left < len(nums) - 1:
            while left < right:
                if nums[left] + nums[right] <= target:
                    result += right - left 
                    break
                else:
                    right -= 1
            left += 1
            right = len(nums) - 1

        return result
