class Solution:
    def twoSum(self, nums, num_a, num_b, num_c, num_d, target, result):
        while num_c < num_d:
            value = nums[num_c] + nums[num_d]
            if value > target:
                num_d -= 1
            elif value < target:
                num_c += 1
            else:
                result.append([nums[num_a], nums[num_b], nums[num_c], nums[num_d]])
                num_c = self.pass_repeated_number(nums, num_c, num_d, "LEFT")
                num_d = self.pass_repeated_number(nums, num_c, num_d, "RIGHT")
                num_c, num_d = num_c + 1, num_d - 1
    
    def pass_repeated_number(self, nums, left, right, side):
        if side == "LEFT":
            while left < right and nums[left] == nums[left + 1]:
                left += 1
            return left
        while right > left and nums[right] == nums[right - 1]:
            right -= 1
        return right
    
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        if not nums or len(nums) < 4:
            return []
        
        nums.sort()
        result = []
        num_a, num_b = 0, 1
        while num_a < len(nums) - 3:
            while num_b < len(nums) - 2:
                two_target = target - nums[num_a] - nums[num_b]
                self.twoSum(nums, num_a, num_b, num_b + 1, len(nums) - 1, two_target, result)
                num_b = self.pass_repeated_number(nums, num_b, len(nums) - 2, "LEFT")
                num_b += 1
            num_a = self.pass_repeated_number(nums, num_a, len(nums) - 3, "LEFT")
            num_a, num_b = num_a + 1, num_a + 2
            
        return result
                    
                    

                
                
                
                        
                
        
