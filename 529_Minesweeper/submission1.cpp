#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        if (board[click[0]][click[1]] == 'E') {        
            int count = count_mine(board, click);
            if (count != 0) {
                board[click[0]][click[1]] = count + '0';
            }
            else {
                board[click[0]][click[1]] = 'B';
                for (int i = -1; i<2; i++) {
                    for (int j=-1; j<2; j++) {
                        if (click[0] + i >=0 && click[0] + i < board.size() && 
                                click[1] + j >=0 && click[1] + j < board[0].size()) {
                            if (board[click[0] + i][click[1] + j] == 'E') {
                                vector<int> nextclick {click[0] + i, click[1] + j};
                                board = updateBoard(board, nextclick);
                            }
                        }
                    }
                }
            }
        }
        return board;
    }
private:
    int count_mine(vector<vector<char>>& board, vector<int>& click) {
        int count = 0;
        for (int i = -1; i<2; i++) {
            for (int j=-1; j<2; j++) {
                if (click[0] + i >=0 && click[0] + i < board.size() && 
                        click[1] + j >=0 && click[1] + j < board[0].size()) {
                    if (board[click[0] + i][click[1] + j] == 'M') {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
