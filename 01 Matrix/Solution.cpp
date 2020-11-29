class Solution{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int direction[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        int row, column;
        queue<pair<int, int>> Q;
        row = matrix.size();
        column = matrix[0].size();
        vector<vector<int>> distance (row, vector<int>(column, INT_MAX - 10000));
        for (int i = 0; i < row; i++)
            for (int j = 0; j < column; j++)
                if (matrix[i][j] == 0)
                   distance[i][j] = 0;
                else{
                    if (i > 0)
                        distance[i][j] = min(distance[i][j], distance[i-1][j]+1);
                    if (j > 0)
                        distance[i][j] = min (distance[i][j], distance[i][j-1]+1);
                }
        for (int i = row - 1; i >= 0; i--){
            for (int j = column - 1; j >= 0; j--){
                if (i < row - 1)
                    distance[i][j] = min (distance[i][j], distance[i+1][j] + 1);
                if (j < column - 1)
                    distance[i][j] = min (distance[i][j], distance[i][j+1] + 1);
            }
        }
        // for (int x = 0; x < row; x++)
        //     for (int y = 0; y < column; y++){
        //         for (int i = 0; i < 4; i++){
        //             int nextX = x + direction[i][0];
        //             int nextY = y + direction[i][1];
        //             if (nextX >= 0 && nextX < row && nextY >=0 && nextY < column)
        //                 distance[x][y] = min(distance[nextX][nextY] + 1, distance[x][y]);
        //          }
        //     }
        // for (int x = 0; x < row; x++)
        //     for (int y = 0; y < column; y++){
        //         for (int i = 0; i < 4; i++){
        //             int nextX = x + direction[i][0];
        //             int nextY = y + direction[i][1];
        //             if (nextX >= 0 && nextX < row && nextY >=0 && nextY < column)
        //                 distance[x][y] = min(distance[nextX][nextY] + 1, distance[x][y]);
        //          }
        //     }
        return distance;
    }
};
// Check left and top first then right and bot
