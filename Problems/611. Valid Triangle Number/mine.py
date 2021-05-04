class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        if not nums or len(nums) < 3:
            return 0
        
        nums.sort()
        ans = 0
        for maxIndex in range(2, len(nums)):
            ans += self.getTriangleCount(nums, nums[maxIndex], maxIndex)
        
        return ans
    
    def getTriangleCount(self, nums, target, maxIndex):
        left, right = 0, maxIndex - 1
        cnt = 0
        while left < right:
            if nums[left] + nums[right] > target:
                cnt += right - left
                right -= 1
            else:
                left += 1
        
        return cnt
        
