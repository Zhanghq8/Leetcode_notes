#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() == true || board[0].empty() == true) {
            return;
        }
        vector<vector<bool>> visited(board.size(), vector<bool> (board[0].size(), false));
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[i].size(); j++) {
                if ((i==0 || i==board.size()-1 || j==0 || j==board[i].size()-1) && board[i][j] == 'O') {
                    cout << i << " " << j << endl;
                    dfs_border(board, visited, i, j);
                }
            }
        }
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[i].size(); j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == '$') {
                    board[i][j] = 'O';
                }
            }
        }
    }
private:
    void dfs_border(vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y) {
        if (x<0 || y<0 || x>=board.size() || y>=board[x].size()) {
            return;
        }
        if (board[x][y] == 'X') {
            return;
        }
        if (visited[x][y] == true) {
            return;
        }
        visited[x][y] = true;
        board[x][y] = '$';
        dfs_border(board, visited, x-1, y);
        dfs_border(board, visited, x+1, y);
        dfs_border(board, visited, x, y-1);
        dfs_border(board, visited, x, y+1);
    }
    
};
