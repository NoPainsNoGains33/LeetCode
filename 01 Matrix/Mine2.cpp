class Solution{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> distance;
        int direction[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        int row, column;
        queue<pair<int, int>> Q;
        row = matrix.size();
        column = matrix[0].size();
        for (int i = 0; i < row; i++){
            vector<int> currentRow;
            for (int j = 0; j < column; j++){
                if (matrix[i][j] == 0){
                   currentRow.push_back(0);
                    Q.push({i, j}); 
                }
                else
                    currentRow.push_back(-1);   
            }
            distance.push_back(currentRow);
        }
        Q.push({-1, -1});
        int currentDistance = 0;
        while (!Q.empty()){
            int x = Q.front().first;
            int y = Q.front().second;
            Q.pop();
            if (x == -1){
                currentDistance++;
                if (!Q.empty())
                    Q.push({-1, -1});
                continue;
            }
            // if (distance[x][y] != 0 && distance[x][y] != -1)
            //     distance[x][y] = min (distance[x][y], currentDistance+1);
            for (int i = 0; i < 4; i++){
                int nextX = x + direction[i][0];
                int nextY = y + direction[i][1];
                if (nextX >= 0 && nextX < row && nextY >=0 && nextY < column){
                    if (distance[nextX][nextY] == -1){
                        distance[nextX][nextY] = currentDistance + 1;
                        Q.push({nextX, nextY});
                    }
                }
            }
        }
        return distance;
    }
};
