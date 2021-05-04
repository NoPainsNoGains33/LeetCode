bool myfunc (const string& i, const string& j){
        return (i<j);
    }
class Solution {
private:
    int len;
    unordered_map<string, vector<string>> flightMap;
    vector<string> result;
public:
    void helper (string start, int so_far, unordered_map<string, vector<bool>>flag, vector<string> lists){
        if (so_far == len){
            result = lists;
            return;
        }
        for (int i = 0; i < flightMap[start].size(); i++){
            if (flag[start][i] == false){
                flag[start][i] = true;
                lists.push_back(flightMap[start][i]);
                helper(flightMap[start][i], so_far+1, flag, lists);
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
        unordered_map<string, vector<bool>>flag;
        for (auto it:tickets)
            flightMap[it[0]].push_back(it[1]);
        for (auto& it:flightMap){
            int len = it.second.size();
            for (int i = 0; i < len; i++)
                flag[it.first].push_back(false);
            sort(it.second.begin(), it.second.end(), myfunc);
        }
        // for (auto it:flightMap){
        //     cout << it.first<<endl;
        //     for (auto it2:it.second)
        //         cout <<it2<<" ";
        //     cout<<endl;
        // }
        helper ("JFK", 0, flag, vector<string>{"JFK"});
        return result;
    }
};
// Checked answers almost time limit exceeded
