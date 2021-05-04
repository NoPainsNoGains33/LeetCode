class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "")
            return 0;
        int n = haystack.size(), m = needle.size();
        for (int i = 0; i < n - m + 1; i++){
            int j = 0;
            while (j < m && haystack[i+j] == needle[j])
                j++;
            if (j == m)
                return i;
        }
        return -1;
    }
};

// Actually, instead of O(n*m), it is O((n-m)*m)
