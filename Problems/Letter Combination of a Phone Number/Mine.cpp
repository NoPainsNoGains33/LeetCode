class Solution {
private:
    vector<string> results;
    int len;
    vector<string> nums = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string s = "";
    vector<int> num;
public:
    void dfs (int i){
        if (i == len){
            results.push_back(s);
            return;
        }
        for (int j = 0; j < nums[num[i]].size(); j++){
            s += nums[num[i]][j];
            dfs (i + 1);
            s = s.substr (0, s.size() - 1);
        }
    }
    vector<string> letterCombinations(string digits) {
        len = digits.size();
        if (len == 0)
            return {};
        for (int i = 0; i < len; i++)
            num.push_back (digits[i] - '0');
        dfs (0);
        return results;
    }
};
