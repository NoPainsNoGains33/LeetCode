class Solution:
    def longestPalindrome(self, s: str) -> int:
        if not s:
            return 0
        
        letter_to_cnt_map = {}
        result = 0
        odd_existed = 0
        for char in s:
            letter_to_cnt_map[char] = letter_to_cnt_map.get(char, 0) + 1
        for value in letter_to_cnt_map.values():
            if odd_existed == 0 and value % 2:
                odd_existed = 1
            result += value // 2 * 2
        
        return result + odd_existed
        
