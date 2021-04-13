// 绝了我他妈真是个天才 这都能写出来
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return {};
        unordered_map<int, int> hash_map;
        for (int k = 0; k < n; k++)
            hash_map[nums[k]]++;
        set<vector<int>> result;
        for(unordered_map<int, int>::iterator i = hash_map.begin(); i != hash_map.end(); i++){
            (*i).second--;
            for (unordered_map<int, int>::iterator j = i; j != hash_map.end(); j++){
                if (j->second > 0){
                    (*j).second--;
                    if (hash_map.find(- i->first - j->first) != hash_map.end() && hash_map[- i->first - j->first] != 0){
                        vector<int> temp = {i->first, j->first, - i->first - j->first};
                        sort(temp.begin(), temp.end());
                        result.insert(temp);
                    }
                    (*j).second++;
                }
            }
            (*i).second++;
        }
        return vector<vector<int>> (begin(result), end(result));
    }
};



// 改写成auto
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return {};
        unordered_map<int, int> hash_map;
        for (int k = 0; k < n; k++)
            hash_map[nums[k]]++;
        set<vector<int>> result;
        for(auto i = hash_map.begin(); i != hash_map.end(); i++){
            i->second--;
            for (auto j = i; j != hash_map.end(); j++){
                if (j->second > 0){
                    j->second--;
                    if (hash_map.find(- i->first - j->first) != hash_map.end() && hash_map[- i->first - j->first] != 0){
                        vector<int> temp = {i->first, j->first, - i->first - j->first};
                        sort(temp.begin(), temp.end());
                        result.insert(temp);
                    }
                    j->second++;
                }
            }
            i->second++;
        }
        return vector<vector<int>> (begin(result), end(result));
    }
};

