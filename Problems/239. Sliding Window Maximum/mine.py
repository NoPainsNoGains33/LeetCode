class MonotonicQueue:
    def __init__(self):
        self.data = collections.deque()
        
    def push(self, val):
        while self.data and self.data[-1] < val:
            self.data.pop()
        self.data.append(val)
        
    def pop(self):
        self.data.popleft()
    
    def max(self):
        return self.data[0]


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if len(nums) * k == 0:
            return []
        if k == 1:
            return nums
        
        ans = []
        monotonic_queue = MonotonicQueue();
        for i in range(len(nums)):
            monotonic_queue.push(nums[i])
            if i - k + 1 >= 0:
                ans.append(monotonic_queue.max())
                if nums[i - k + 1] == monotonic_queue.max():
                    monotonic_queue.pop()
        
        return ans
