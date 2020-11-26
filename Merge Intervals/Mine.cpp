bool myfun (const vector<int>& i, const vector<int>& j){
    return (i[0] < j[0]);
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort first
        int len = intervals.size();
        if (len == 0 || len == 1)
            return intervals;
        sort (intervals.begin(), intervals.end(), myfun);
        // for (auto interval: intervals)
        //     cout << interval[0] << " " << interval[1] << endl;
        // then merge
        vector<vector<int>> result;
        vector<int> current = intervals[0];
        for (int i = 1; i < len; i++){
            if (intervals[i][0] <= current[1])
                current[1] = max(current[1], intervals[i][1]);
            else{
                result.push_back (current);
                current = intervals[i];
            }
        }
        result.push_back(current);
        return result;
    }
};
