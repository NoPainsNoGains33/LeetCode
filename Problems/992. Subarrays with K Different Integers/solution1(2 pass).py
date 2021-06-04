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
        
        count = collections.Counter()
        return self.countAtMostKDistinct(nums, k) - self.countAtMostKDistinct(nums, k - 1)
    
    def countAtMostKDistinct(self, nums, k):
        count = collections.Counter()
        res, curr_distinct_nums, start_index = 0, 0, 0
        for end_index in range(0, len(nums)):
            count[nums[end_index]] += 1
            if count[nums[end_index]] == 1:
                curr_distinct_nums += 1
            if curr_distinct_nums > k:
                while count[nums[start_index]] > 1:
                    count[nums[start_index]] -= 1
                    start_index += 1
                count[nums[start_index]] -= 1
                start_index += 1
                curr_distinct_nums -= 1
            res += end_index - start_index + 1
        return res
