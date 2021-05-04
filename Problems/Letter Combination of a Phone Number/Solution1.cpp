class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int len = digits.size();
        if (len == 0)
            return {};
        vector<string> results;
        vector<string> nums = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        results.push_back("");
        for (int i = 0; i < len; i++){
            string current = nums[digits[i] - '0'];
            vector<string> temp;
            for (int j = 0; j < current.size(); j++)
                for (int k = 0; k < results.size(); k++)
                    temp.push_back (results[k] + current[j]);
            results.swap (temp);
        }
        return results;
    }
};
