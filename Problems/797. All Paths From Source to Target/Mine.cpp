class Solution {
private:
    vector<vector<int>> result;
    vector<vector<int>> map;
    vector<int> route{0};
    int dest;
public:
    void dfs (int current){
        if (current == dest){
            result.push_back(route);
            return;
        }
        for (int i = 0; i < map[current].size(); i++){
            route.push_back(map[current][i]);
            dfs(map[current][i]);
            route.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dest = graph.size() - 1;
        map = graph;
        dfs(0);
        return result;
    }
};
