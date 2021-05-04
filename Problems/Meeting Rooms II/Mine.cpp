bool myfunc (const vector<int>& i, const vector<int>& j){
    return (i[0] < j[0]);
}
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int len = intervals.size();
        int i;
        if (len == 0)
             return 0;
        // record rooms using time
        vector<int> rooms;
        // sort meeting times as incending order with start time
        sort (intervals.begin(), intervals.end(), myfunc);
        for (auto interval:intervals){
            if (rooms.empty()){
                rooms.push_back (interval[1]);
                continue;
            }
            else{
                for (i = 0; i < rooms.size(); i++){
                    if (interval[0] >= rooms[i]){
                        rooms[i] = interval[1];
                        break;
                    }
                }
                if (i == rooms.size())
                    rooms.push_back(interval[1]);
            }
        }
        return rooms.size();
    }
};
