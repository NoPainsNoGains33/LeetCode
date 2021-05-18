class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if not nums:
            return -1
        
        left, right = 0, len(nums) - 1
        
        while (left < right - 1):
            mid = (left + right) // 2
            if nums[mid] == target:
                return mid
            # mid is after or at break point
            if nums[mid] < nums[right]:
                if target > nums[mid] and target <= nums[right]:
                    left = mid
                else:
                    right = mid
            else:
                if target < nums[mid] and target >= nums[left]:
                    right = mid
                else:
                    left = mid
        
        if nums[left] == target:
            return left
        if nums[right] == target:
            return right
        return -1
                    

                        
