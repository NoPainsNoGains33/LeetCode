class TwoSum:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.nums = []
        

    def add(self, number: int) -> None:
        """
        Add the number to an internal data structure..
        """
        self.nums.append(number)
        index = len(self.nums) - 1
        while index > 0 and self.nums[index] < self.nums[index - 1]:
            self.nums[index], self.nums[index - 1] = \
            self.nums[index - 1], self.nums[index]
            index -= 1

    def find(self, value: int) -> bool:
        """
        Find if there exists any pair of numbers which sum is equal to the value.
        """
        left, right = 0, len(self.nums) - 1
        while left < right:
            sums = self.nums[left] + self.nums[right]
            if sums == value:
                return True
            elif sums > value:
                right -= 1
            else:
                left += 1
        
        return False
        
        


# Your TwoSum object will be instantiated and called as such:
# obj = TwoSum()
# obj.add(number)
# param_2 = obj.find(value)
