#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[i].size(); j++) {
                if (dfs(board, i, j, 0, word) == true) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char>>& board, int row, int col, int count, string word) {
        if (count == word.size()) {
            return true;
        }
        if (row < 0 || row >= board.size() || col < 0 || col >= board[row].size() || board[row][col] != word[count]) {
            return false;
        }
        char current = board[row][col];
        board[row][col] = ' ';
        bool isFound = dfs(board, row-1, col, count+1, word)
            || dfs(board, row+1, col, count+1, word)
            || dfs(board, row, col-1, count+1, word)
            || dfs(board, row, col+1, count+1, word);
        board[row][col] = current;
        return isFound;
    }
};