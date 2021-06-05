class Solution:
    def build_character_set(self, nums, start_index, end_index):
        character_set = set()
        for index in range(start_index, end_index + 1):
            character_set.add(nums[index])
        return character_set
    
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        if len(nums) == 0 or k == 0:
            return 0
        
        res = 0
        for start_index in range(0, len(nums) - k + 1):
            for end_index in range(start_index + k - 1, len(nums)):
                if end_index == start_index + k - 1:
                    character_set = self.build_character_set(nums, start_index, end_index)
                character_set.add(nums[end_index])
                if len(character_set) == k:
                    res += 1
                if len(character_set) > k:
                    break

        return res
