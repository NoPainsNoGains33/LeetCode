class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int column = grid[0].size();
        int rotten = 0;
        int fresh = 0;
        int minutes = -1;
        queue <pair<int, int>> rotten_oranges;
        int i, j;
        for (i = 0; i < row; i++)
            for (j = 0; j < column; j++){
                if (grid[i][j] == 2){
                    rotten++;
                    rotten_oranges.push({i, j});
                }
                if (grid[i][j] == 1)
                    fresh++;
            }
        rotten_oranges.push({-1, -1});
        while (!rotten_oranges.empty()){
            pair<int, int> temp = rotten_oranges.front();
            rotten_oranges.pop();
            if (temp.first == -1){
                minutes++;
                if (!rotten_oranges.empty())
                    rotten_oranges.push({-1, -1});
            }
            else{
                if (temp.first - 1 >= 0 && grid[temp.first - 1][temp.second] == 1){
                    grid[temp.first - 1][temp.second] = 2;
                    rotten_oranges.push({temp.first - 1, temp.second});
                    fresh--;
                }
                if (temp.second - 1 >= 0 && grid[temp.first][temp.second - 1] == 1){
                    grid[temp.first][temp.second - 1] = 2;
                    rotten_oranges.push({temp.first, temp.second - 1});
                    fresh--;
                }
                if (temp.first + 1 < row && grid[temp.first + 1][temp.second] == 1){
                    grid[temp.first + 1][temp.second] = 2;
                    rotten_oranges.push({temp.first + 1, temp.second});
                    fresh--;
                }
                if (temp.second + 1 < column && grid[temp.first][temp.second + 1] == 1){
                    grid[temp.first][temp.second + 1] = 2;
                    rotten_oranges.push({temp.first, temp.second+1});
                    fresh--;
                }  
            }
        }
        
        if (fresh != 0)
            return -1;
        return minutes;           
    }
};
