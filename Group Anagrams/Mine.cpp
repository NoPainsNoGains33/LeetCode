class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> umap;
        int len = strs.size();
        for (auto str:strs){
            string temp = str;
            sort(temp.begin(), temp.end());
            umap[temp].push_back(str);
        }
        vector<vector<string>> result;
        for (auto it:umap)
            result.push_back(it.second);
        return result;
    }
};
