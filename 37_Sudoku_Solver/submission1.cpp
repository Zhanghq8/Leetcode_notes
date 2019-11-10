#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        row_flag = vector<vector<bool>> (board.size(), vector<bool> (board[0].size(), false));
        col_flag = vector<vector<bool>> (board.size(), vector<bool> (board[0].size(), false));
        cell_flag = vector<vector<bool>> (board.size(), vector<bool> (board[0].size(), false));
        getState(board);
        bool result = dfs(0, 0, board);
    }
private:
    vector<vector<bool>> row_flag, col_flag, cell_flag;
    void getState (vector<vector<char>>& board) {
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[i].size(); j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1;
                    row_flag[i][num] = true;
                    col_flag[j][num] = true;
                    cell_flag[i/3*3+j/3][num] = true;
                }
            }
        }
    }
    bool dfs(int x, int y, vector<vector<char>>& board) {
        if (x == 9) {
            return true;
        }
        int next_y = (y+1)%9;
        int next_x = (next_y == 0) ? x+1 : x;
        if (board[x][y] != '.') {
            return dfs(next_x, next_y, board);
        }
        for (int i=1; i<=9; i++) {
            if (!row_flag[x][i-1] && !col_flag[y][i-1] && !cell_flag[x/3*3+y/3][i-1]) {
                row_flag[x][i-1] = true;
                col_flag[y][i-1] = true;
                cell_flag[x/3*3+y/3][i-1] = true;
                board[x][y] = i + '0';
                if (dfs(next_x, next_y, board)) {
                    return true;
                }
                row_flag[x][i-1] = false;
                col_flag[y][i-1] = false;
                cell_flag[x/3*3+y/3][i-1] = false;
                board[x][y] = '.';
            }
        }
        return false;
    }
};