class Solution{
private:
    vector<vector<int>> Matrix;
    vector<vector<int>> distance;
    int direction[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int row, column;
public:
    int BFS (int x, int y, int currentDistance){
        // if (Matrix[x][y] == 0)
        //     return currentDistance;
        queue<pair<int, int>> Q;
        Q.push({x, y});
        int minDistance = INT_MAX;
        while (!Q.empty()){
            pair<int, int> temp = Q.front();
            int X = temp.first;
            int Y = temp.second;
            Q.pop();
            for (int i = 0; i < 4; i++){
                int nextX = X + direction[i][0];
                int nextY = Y + direction[i][1];
                if (nextX >= 0 && nextX < row && nextY >=0 && nextY < column){
                    if (Matrix[nextX][nextY] == 0)
                        minDistance = min(currentDistance + 1, minDistance);
                    else
                        if (distance[nextX][nextY] != -1)
                            minDistance = min(distance[nextX][nextY] + 1, minDistance);
                    Q.push({nextX, nextY});
                }
            }
            if (minDistance != INT_MAX)
                break;
            currentDistance++;
        }
        return minDistance;
    }
    void update (int x, int y){
        for (int i = 0; i < 4; i++){
                int nextX = x + direction[i][0];
                int nextY = y + direction[i][1];
                if (nextX >= 0 && nextX < row && nextY >=0 && nextY < column)
                    distance[x][y] = min(distance[nextX][nextY] + 1, distance[x][y]);
            }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        Matrix = matrix;
        for (auto it:matrix){
            vector<int> currentRow;
            for (auto it2:it)
                if (it2 == 0)
                    currentRow.push_back(0);
                else
                    currentRow.push_back(-1);
            distance.push_back(currentRow);
        }
        row = matrix.size();
        column = matrix[0].size();
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[i].size(); j++){
                if (distance[i][j] != -1)
                    continue;
                distance[i][j] = BFS (i, j, 0);
            }
        }
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[i].size(); j++){
                if (distance[i][j] != 0)
                    update(i, j);
            }
        }
        return distance;
    }
};
