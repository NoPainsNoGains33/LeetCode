class Solution {
public:
    /**
     * @param s: input string
     * @return: a string as the longest palindromic substring
     */
    string longestPalindrome(string &s) {
        // write your code here
        if (s == "")
            return "";

        string longest = "";
        for (int middle = 0; middle < s.size(); middle++){
            // Odd
            string tempOddLongest = getPalindrome(s, middle, middle);
            if (tempOddLongest.size() > longest.size())
                longest = tempOddLongest;
            // Even
            string tempEvenLongest = getPalindrome(s, middle, middle + 1);
            if (tempEvenLongest.size() > longest.size())
                longest = tempEvenLongest;
        }

        return longest;
    }

    string getPalindrome(string &s, int left, int right){
        string longest = "";
        while (left >= 0 && right < s.size()){
            if (s[left] == s[right]){
                longest = s.substr(left, right - left + 1);
                left--, right++;
            }
            else
                break;
        }

        return longest;
    }
};
