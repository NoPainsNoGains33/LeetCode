class Solution {
private:
    vector<vector<int>> result;
    vector<vector<int>> map;
    vector<int> route;
    int dest;
public:
    void dfsHelper (int current){
        route.push_back(current);
        if (current == dest)
            result.push_back(route);
        else
            for (int i = 0; i < map[current].size(); i++)
                dfsHelper(map[current][i]);
        route.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dest = graph.size() - 1;
        map = graph;
        dfsHelper(0);
        return result;
    }
};
