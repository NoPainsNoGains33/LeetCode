class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int rows = grid.size();
        if (rows == 0)
            return 0;
        int columns = grid[0].size();
        int result = 0, row_hit = 0;
        vector<int> col_hit(columns, 0);
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < columns; j++){
                if (j == 0 || grid[i][j-1] == 'W'){
                    row_hit = 0;
                    for (int k = j; k < columns; k++){
                        if (grid[i][k] == 'W')
                            break;  
                        if (grid[i][k] == 'E')
                            row_hit++;
                    }
                }
                    
                if (i == 0 || grid[i-1][j] == 'W'){
                    col_hit[j] = 0;
                    for (int k = i; k < rows; k++){
                        if (grid[k][j] == 'W')
                            break;
                        if (grid[k][j] == 'E')
                            col_hit[j]++;
                    }
                }
                
                if (grid[i][j] == '0')
                    result = result > row_hit + col_hit[j]? result:row_hit + col_hit[j];         
            }
        }
        return result;
    }
};

//Looks Like DP
