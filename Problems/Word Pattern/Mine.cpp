class Solution{
public:
    bool wordPattern (string pattern, string s){
        unordered_map<char, vector<int>> hashMap;
        vector<string> S;
        for (int i = 0; i < pattern.size(); i++)
            hashMap[pattern[i]].push_back(i);
        string currentS = "";
        for (auto it:s){
            if (it != ' ')
                currentS += it;
            else{
                S.push_back(currentS);
                currentS = "";
            }
        }
        S.push_back(currentS);
        vector<string> allStrings;
        if (pattern.size() != S.size())
            return false;
        for (auto it:hashMap){
            string currentString = S[it.second[0]];
            if (!allStrings.empty() && find(allStrings.begin(), allStrings.end(), currentString) != allStrings.end())
                return false;
            else
                allStrings.push_back(currentString);
            for (auto it2:it.second){
                if (S[it2] != currentString)
                    return false;
            }
        }
        return true;
    }
};
