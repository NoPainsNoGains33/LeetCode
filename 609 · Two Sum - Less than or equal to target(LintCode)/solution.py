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
        cnt = 0
        while left < right:
            value = nums[left] + nums[right]
            # That means this right no longer considered
            if value > target:
                right -= 1
            else:
                cnt += right - left
                left += 1

        return cnt
