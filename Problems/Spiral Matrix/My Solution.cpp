class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (row == 0)
            return {};
        int col = matrix[0].size();
        vector<vector<int>>vis(row, vector<int>(col));
        vector<int>result(row*col);
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int x = 0, y = 0, pos = 0;
        int d_number = 0;
        int x_row, y_col;
        while (pos < row*col){
            result[pos++] = matrix[x][y];
            vis[x][y] = 1;
            x_row = dir[d_number][0];
            y_col = dir[d_number][1];
            if (x + x_row < row && x + x_row >= 0 && y + y_col < col && y + y_col >=0 && vis[x+x_row][y+y_col] == 0){
                x += x_row;
                y += y_col;
            }
            else{
                d_number = (d_number+1) % 4;
                x += dir[d_number][0];
                y += dir[d_number][1];
            }
        }
        return result;
    }
};
