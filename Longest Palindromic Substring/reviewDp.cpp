class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, len = 1;
        int stringLen = s.length();
        bool p[stringLen][stringLen];
        for (int i = stringLen - 1; i >= 0; i--)
            for (int j = i; j <= stringLen - 1; j++){
                if (s[i] == s[j]){
                   if (j - i < 3 || (j - 1 >= 0 && i + 1 < stringLen && p[i+1][j-1])){
                        p[i][j] = true;
                        if (j - i + 1 > len){
                            len = j - i + 1;
                            start = i;
                        }
                       continue;
                    } 
                }
                p[i][j] = false;
            }
        return s.substr(start, len);
    }
};
