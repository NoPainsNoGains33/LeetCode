class Solution:
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        if len(nums) == 0 or k == 0:
            return 0
        
        count = collections.Counter()
        first, last, curr_distinct, res = 0, 0, 0, 0
        for end in range(0, len(nums)):
            # Add end into counter
            count[nums[end]] += 1
            if count[nums[end]] == 1:
                curr_distinct += 1
            # If curr_distinct > k
            if curr_distinct > k:
                while count[nums[last]] > 1:
                    count[nums[last]] -= 1
                    last += 1
                count[nums[last]] -= 1
                last += 1
                first = last
                curr_distinct -= 1
            # Maintain last
            while last < end and count[nums[last]] > 1:
                count[nums[last]] -= 1
                last += 1
            # Add res
            if curr_distinct == k:
                res += last - first + 1
        return res
