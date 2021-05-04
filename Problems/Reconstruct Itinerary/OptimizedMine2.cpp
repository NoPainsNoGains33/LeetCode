bool myfunc (const string& i, const string& j){
        return (i<j);
    }
class Solution {
private:
    int len;
    unordered_map<string, vector<string>> flightMap;
    unordered_map<string, vector<bool>>flag;
    vector<string> result;
    vector<string> lists;
public:
    void helper (string start, int so_far){
        if (so_far == len){
            result = lists;
            return;
        }
        for (int i = 0; i < flightMap[start].size(); i++){
            if (flag[start][i] == false){
                flag[start][i] = true;
                lists.push_back(flightMap[start][i]);
                helper(flightMap[start][i], so_far+1);
                if (!result.empty())
                    return;
                flag[start][i] = false;
                lists.pop_back();
            }
        }
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        len = tickets.size();
        if (len == 1)
            return tickets[0];
        for (auto it:tickets)
            flightMap[it[0]].push_back(it[1]);
        for (auto& it:flightMap){
            int len = it.second.size();
            for (int i = 0; i < len; i++)
                flag[it.first].push_back(false);
            sort(it.second.begin(), it.second.end(), myfunc);
        }
        lists.push_back("JFK");
        helper ("JFK", 0);
        return result;
    }
};
// Understand more about traceback, so optimized
