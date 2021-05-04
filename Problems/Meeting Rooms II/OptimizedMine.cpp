bool myfunc (const vector<int>& i, const vector<int>& j){
    return (i[0] < j[0]);
}
struct compare{
    bool operator() (const int& i, const int&j){
        return i > j;
    }
};
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int len = intervals.size();
        int i;
        if (len == 0)
             return 0;
        // record rooms using time
        priority_queue<int, vector<int>, compare> rooms;
        // sort meeting times as incending order with start time
        sort (intervals.begin(), intervals.end(), myfunc);
        for (auto interval:intervals){
            if (rooms.empty()){
                rooms.push (interval[1]);
                continue;
            }
            else{
                if (rooms.top() > interval[0])
                    rooms.push(interval[1]);
                else{
                    rooms.pop();
                    rooms.push(interval[1]);
                }
            }
        }
        return rooms.size();
    }
};

