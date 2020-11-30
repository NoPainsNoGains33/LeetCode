

bool myfunc (const vector<int>& i, const vector<int>& j){
    return (i[0] < j[0]);
}

class Solution{
private:
    vector<vector<int>> matrix;
    int row, col;
public:
int BFS (int startX, int startY, int destX, int destY){
        const int INF = INT_MAX - 100000;
        if (startX == destX && startY == destY)
            return 0;
        int direction[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1,  0}};
        int currentDistance = 0;
        vector<vector<int>> dist (row, vector<int> (col, INF));
        queue<pair<int, int>> Q;
        Q.push({startX, startY});
        dist[startX][startY] = 0;
        while (!Q.empty()){
            pair<int, int> cur = Q.front();
            Q.pop();
            for (int i = 0; i < 4; i++){
                int nextX = cur.first + direction[i][0];
                int nextY = cur.second + direction[i][1];
                if (nextX < 0 || nextX >= row || nextY < 0 || nextY >= col || matrix[nextX][nextY] == 0 || dist[nextX][nextY] != INF)
                    continue;
                dist[nextX][nextY] = dist[cur.first][cur.second] + 1;
                if (nextX == destX && nextY == destY)
                    return dist[nextX][nextY];
                Q.push({nextX, nextY});
            }
        }
        return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        matrix = forest;
        vector<vector<int>> nodes;
        // Preprocess forest
        row = matrix.size();
        col = matrix[0].size();
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if (matrix[i][j] > 1){
                    nodes.push_back({matrix[i][j], i, j});
                }
            }
        }
        sort (nodes.begin(), nodes.end(), myfunc);
        int distance = 0;
        int currentDistance;
        currentDistance = BFS (0, 0, nodes[0][1], nodes[0][2]);
        if (currentDistance == -1)
            return -1;
        else
            distance += currentDistance;
        matrix[nodes[0][1]][nodes[0][2]] = 1;
        // Start from (0, 0) to go next tree
        for (int i = 0; i < nodes.size()-1; i++){
                currentDistance = BFS (nodes[i][1], nodes[i][2], nodes[i+1][1], nodes[i+1][2]);
            if (currentDistance == -1)
                return -1;
            distance += currentDistance;
            matrix[nodes[i+1][1]][nodes[i+1][2]] = 1;
        }
        return distance;
    }
};
