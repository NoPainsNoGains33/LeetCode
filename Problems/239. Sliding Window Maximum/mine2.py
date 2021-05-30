// Try to reduce time by not defining class
// Does not work lmao

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if len(nums) * k == 0:
            return []
        if k == 1:
            return nums
        
        def _push_in_queue(monotonic_queue, val):
            while monotonic_queue and monotonic_queue[-1] < val:
                monotonic_queue.pop()
            monotonic_queue.append(val)
        
        ans = []
        monotonic_queue = collections.deque()
        for i in range(len(nums)):
            _push_in_queue(monotonic_queue, nums[i])
            if i - k + 1 >= 0:
                ans.append(monotonic_queue[0])
                if nums[i - k + 1] == monotonic_queue[0]:
                    monotonic_queue.popleft()
        
        return ans
