class Solution:
    def isPalindrome(self, s: str) -> bool:        
        left, right = 0, len(s) - 1
        while left < right:
            while left < right and not self.is_valid(s[left]):
                left += 1
            while left < right and not self.is_valid(s[right]):
                right -= 1
            if left < right and s[left].lower() != s[right].lower():
                return False
            left += 1
            right -= 1
        
        return True
    
    def is_valid(self, char):
        return char.isdigit() or char.isalpha()
