class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> final_matrix;
        // int direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        // cout << direction[0][0];
        int matrix[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                matrix[i][j] = 0;
        int value = 1;
        int x = 0, y = 0;
        int d_number = 0;
        int row, col;
        while (value <= n*n){
            matrix[x][y] = value++;
            row = direction[d_number].first;
            col = direction[d_number].second;
            if (x + row < n && x + row>=0 && y + col < n && y + col >=0 && matrix[x + row][y + col] == 0){
                x+=row;
                y+=col;
            }
            else{
                d_number = (d_number + 1) % 4;
                x+=direction[d_number].first;
                y+=direction[d_number].second;
            }
        }
        // for (int i = 0; i < n; i++)
        //     for (int j = 0; j < n; j++)
        //         cout << matrix[i][j];
        for (int i = 0; i < n; i++){
            vector<int> temp;
            for (int j = 0; j < n; j++)
                temp.push_back(matrix[i][j]);
            final_matrix.push_back(temp);
            
        }
            
        return final_matrix;
    }
};
