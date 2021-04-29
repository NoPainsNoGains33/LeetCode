class Solution:
    def fourSumCount(self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]) -> int:
        count = 0
        two_nums_sum_hash = {}
        
        for num1 in nums1:
            for num2 in nums2:
                two_nums_sum_hash[num1 + num2] = two_nums_sum_hash.get(num1 + num2, 0) + 1
                
        for num3 in nums3:
            for num4 in nums4:
                value = num3 + num4
                if two_nums_sum_hash.get(-value, 0) != 0:
                    count += two_nums_sum_hash[-value]
                    
        return count
