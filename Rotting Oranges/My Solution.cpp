class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int column = grid[0].size();
        int rotten = 0;
        int fresh = 0;
        int minutes = 0;
        vector <pair<int, int>> current_rotten_oranges;
        int i, j;
        for (i = 0; i < row; i++)
            for (j = 0; j < column; j++){
                if (grid[i][j] == 2){
                    rotten++;
                    current_rotten_oranges.push_back({i, j});
                }
                if (grid[i][j] == 1)
                    fresh++;
            }
        if (rotten == 0 && fresh == 0)
            return minutes;
        while (fresh != 0){
            vector<pair<int, int>> temp_vec;
            for (auto temp:current_rotten_oranges){
                if (temp.first - 1 >= 0 && grid[temp.first - 1][temp.second] == 1){
                    grid[temp.first - 1][temp.second] = 2;
                    temp_vec.push_back({temp.first - 1, temp.second});
                    fresh--;
                }
                if (temp.second - 1 >= 0 && grid[temp.first][temp.second - 1] == 1){
                    grid[temp.first][temp.second - 1] = 2;
                    temp_vec.push_back({temp.first, temp.second - 1});
                    fresh--;
                }
                if (temp.first + 1 < row && grid[temp.first + 1][temp.second] == 1){
                    grid[temp.first + 1][temp.second] = 2;
                    temp_vec.push_back({temp.first + 1, temp.second});
                    fresh--;
                }
                if (temp.second + 1 < column && grid[temp.first][temp.second + 1] == 1){
                    grid[temp.first][temp.second + 1] = 2;
                    temp_vec.push_back({temp.first, temp.second+1});
                    fresh--;
                }
            }
            if (temp_vec.empty())
                break;
            current_rotten_oranges = temp_vec;
            minutes++;
        }
        if (fresh != 0)
            return -1;
        return minutes;           
    }
};
