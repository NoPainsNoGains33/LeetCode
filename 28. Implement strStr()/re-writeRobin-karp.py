class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if not needle:
            return 0
        if not haystack or len(haystack) < len(needle):
            return -1
        
        
        BASE = 1000000
        POWER = 1
        for _ in range(len(needle)):
            POWER = POWER * 31 % BASE
            
        hash_needle = 0
        for char in needle:
            hash_needle = (hash_needle * 31 + ord(char)) % BASE
        
        hash_value = 0
        for i in range(len(haystack)):
            hash_value = (hash_value * 31 + ord(haystack[i])) % BASE
            if i < len(needle) - 1:
                continue
            
            if i >= len(needle):
                hash_value = hash_value - (ord(haystack[i - len(needle)]) * POWER) % BASE
                if hash_value < 0:
                    hash_value += BASE
             
            if hash_value == hash_needle:
                # Double check
                if haystack[i - len(needle) + 1 : i + 1] == needle:
                    return i - len(needle) + 1
                
        return -1
