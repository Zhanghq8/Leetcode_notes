#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) {
            return;
        }
        int row = board.size();
        int col = board[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O' && (i == 0 || j == 0 || i == row - 1 || j == col - 1)) {
                    dfs(i, j, board, row, col);
                }
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == '$') {
                    board[i][j] = 'O';
                }
            }
        }
        return;
    }
private:
    vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    void dfs(int x, int y, vector<vector<char>>& board, int rowMax, int colMax) {
        if (x < 0 || x >= rowMax || y < 0 || y >= colMax || board[x][y] != 'O') {
            return;
        }
        board[x][y] = '$';
        for (int i = 0; i < 4; i++) {
            dfs(x+dirs[i][0], y+dirs[i][1], board, rowMax, colMax);    
        }
    }
};
