class Solution {
private:
    int len;
    vector<vector<string>> ticket;
    vector<vector<string>> results;
public:
    void helper (string start, int so_far, vector<bool> flag, vector<string> lists){
        if (so_far == len){
            results.push_back(lists);
            return;
        }
        for (int i = 0; i < len; i++){
            if (ticket[i][0] == start && flag[i] == false){
                flag[i] = true;
                lists.push_back(ticket[i][1]);
                helper(ticket[i][1], so_far+1, flag, lists);
                flag[i] = false;
                lists.pop_back();
            }
        }
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        ticket = tickets;
        len = ticket.size();

        if (len == 1)
            return tickets[0];
        vector<bool>flag(len, false);
        // cout << (ticket[0][0] == "MUC");
        helper ("JFK", 0, flag, vector<string>{"JFK"});
        int min_number = -1;
        string temp_min = "";
        for (int i = 0; i < results.size(); i++){
            string temp = "";
            for (auto it:results[i])
                temp.append(it);
            if (temp_min == ""){
                temp_min = temp;
                min_number = i;
            }
            else
                if (temp < temp_min){
                    temp_min = temp;
                    min_number = i;
                }
        }
        return results[min_number];
        // return vector<string>{};
    }
};
