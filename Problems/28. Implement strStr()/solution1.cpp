// Optimization: match start from 1st letter are the same
// After mismatch, start from next 1st letter are equal
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "")
            return 0;
        int n = haystack.size(), m = needle.size();
        int i = 0;
        while (i < n - m + 1){
            // First alphabet matches
            if (haystack[i] == needle[0]){
                int current_len = 1;
                while(current_len < m && haystack[i+current_len] == needle[current_len])
                    current_len++;
                if (current_len == m)
                    return i;    
            }
            i++;
        }
        return -1;
    }
};
