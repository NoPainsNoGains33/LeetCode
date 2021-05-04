class Solution {
public:
    int BASE = 1000000;
    int strStr(string haystack, string needle) {
        if (needle == "")
            return 0;
        if (haystack == "")
            return -1;
        
        int m = needle.size();
        int POWER = 1;
        for (int i = 0; i < m; i++){
            POWER = (POWER * 31) % BASE;
        }
        
        int targetHash = 0;
        for (int i = 0; i < m; i++){
            targetHash = (targetHash * 31 + needle[i]) % BASE;
        }
        
        int sourceHash = 0;
        for (int i = 0; i < haystack.size(); i++){
            sourceHash = (sourceHash * 31 + haystack[i]) % BASE;
            if (i < m -1)
                continue;
            
            // Minus first alphabet hash
            if (i >= m){
                sourceHash = sourceHash - (haystack[i - m] * POWER) % BASE;
                if (sourceHash < 0)
                    sourceHash += BASE;
            }
            
            // Double check
            if (sourceHash == targetHash){
                if (haystack.substr(i - m + 1, m) == needle)
                    return i - m + 1;
            }
        }
        
        return -1;
    }
};
