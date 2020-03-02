#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start;
        string goal = "123450";
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                start += board[i][j] + '0';
            }
        }
        unordered_set<string> visited;
        vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        int move = -1;
        queue<string> Q;
        Q.push(start);
        while (!Q.empty()) {
            move++;
            for (int i = Q.size(); i > 0; i--) {
                string str = Q.front();
                Q.pop();
                visited.insert(str);
                if (str == goal) {
                    return move;
                }
                int pos = str.find('0');
                int boardX = pos / board[0].size();
                int boardY = pos % board[0].size();
                for (int j = 0; j < 4; j++) {
                    int newX = boardX + dirs[j][0];
                    int newY = boardY + dirs[j][1];
                    int newPos = newX * board[0].size() + newY;
                    if (newX >= 0 && newX < board.size() && newY >= 0 && newY < board[0].size()) {
                        swap(str[newPos], str[pos]);
                        if (!visited.count(str)) {
                            Q.push(str);
                        } 
                        swap(str[newPos], str[pos]);
                    } 
                }
            }
        }
        return -1;
    }
};