class TwoSum:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.numToCntMap = {}
        

    def add(self, number: int) -> None:
        """
        Add the number to an internal data structure..
        """
        self.numToCntMap[number] = self.numToCntMap.get(number, 0) + 1

    def find(self, value: int) -> bool:
        """
        Find if there exists any pair of numbers which sum is equal to the value.
        """
        for num1 in self.numToCntMap:
            num2 = value - num1
            cntNeeded = 2 if num1 == num2 else 1
            if self.numToCntMap.get(num2, 0) >= cntNeeded:
                return True
        
        return False
        
        


# Your TwoSum object will be instantiated and called as such:
# obj = TwoSum()
# obj.add(number)
# param_2 = obj.find(value)
