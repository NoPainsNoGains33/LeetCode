// Add pruning, pass 50/55

class Solution:
    def build_character_set(self, start_index, end_index, nums):
        character_set = set()
        for i in range(start_index, end_index + 1):
            character_set.add(nums[i])
        return character_set
    
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        if len(nums) == 0 or k == 0:
            return 0
        if len(self.build_character_set(0, len(nums) - 1, nums)) < k:
            return 0
        
        res = 0
        for i in range(0, len(nums) - k + 1):
            for j in range(i + k - 1, len(nums)):
                if j == i + k - 1:
                    character_set = self.build_character_set(i, j, nums)
                character_set.add(nums[j])
                if len(character_set) == k:
                    res += 1
                elif len(character_set) > k:
                    break
        
        return res
