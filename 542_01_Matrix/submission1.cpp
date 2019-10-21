#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> directions{{-1,0}, {0,-1}, {0,1}, {1, 0}};
        queue<pair<int, int>> q;
        for (int i=0; i<matrix.size(); i++) {
            for (int j=0; j<matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    q.push({i,j});
                }
                else {
                    matrix[i][j] = INT_MAX;
                }
            }
        }
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            for (auto n : directions) {
                int new_row = front.first + n[0];
                int new_col = front.second + n[1];
                if (new_row < 0 || new_row >= matrix.size() || new_col < 0 || new_col >= matrix[0].size()
                    || matrix[new_row][new_col] <= matrix[front.first][front.second]+1) {
                    continue;
                }
                matrix[new_row][new_col] = matrix[front.first][front.second]+1;
                q.push({new_row, new_col});
            }
        }
        return matrix;
    }
};
