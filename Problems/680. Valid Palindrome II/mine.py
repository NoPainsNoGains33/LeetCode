class Solution:
    def validPalindrome(self, s: str) -> bool:
        # Find difference
        left, right = self.find_difference(s, 0, len(s) - 1)
        # Remove one character at left, find difference
        if left < right:
            leftRemoveLeft, rightRemoveLeft = self.find_difference(s, left + 1, right)
        else:
            return True
        # Remove right character at right, find difference
        if leftRemoveLeft < rightRemoveLeft:
            leftRemoveRight, rightRemoveRight = self.find_difference(s, left, right - 1)
        else:
            return True
        
        if leftRemoveRight >= rightRemoveRight:
            return True
        # Still have difference, return False
        return False
    
    def find_difference(self, s, left, right):
        while left < right:
            if s[left] == s[right]:
                left += 1
                right -= 1
            else:
                break
        
        return left, right
