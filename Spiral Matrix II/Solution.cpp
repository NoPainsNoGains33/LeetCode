class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> final_matrix(n, vector<int> (n));
        int value = 1;
        int x = 0, y = 0;
        int d_number = 0;
        int row, col;
        while (value <= n*n){
            final_matrix[x][y] = value++;
            row = direction[d_number][0];
            col = direction[d_number][1];
            if (x + row < n && x + row>=0 && y + col < n && y + col >=0 && final_matrix[x + row][y + col] == 0){
                x+=row;
                y+=col;
            }
            else{
                d_number = (d_number + 1) % 4;
                x+=direction[d_number][0];
                y+=direction[d_number][1];
            }
        }          
        return final_matrix;
    }
};
