#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rowflag (9, vector<bool> (9, false)); 
        vector<vector<bool>> colflag (9, vector<bool> (9, false)); 
        vector<vector<bool>> cellflag (9, vector<bool> (9, false)); 
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[i].size(); j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                int index = board[i][j] - '1';
                if (rowflag[index][i] || colflag[j][index] || cellflag[i/3*3+index/3][j/3*3+index%3]) {
                    cout << rowflag[index][i] << colflag[j][index] << cellflag[i/3+index/3][j/3*2+index/3] << endl;
                    cout << i << j << index<<endl;
                    return false;
                }
                rowflag[index][i] = true;
                colflag[j][index] = true;
                cellflag[i/3*3+index/3][j/3*3+index%3] = true;
            }
        }
        return true;
    }
};