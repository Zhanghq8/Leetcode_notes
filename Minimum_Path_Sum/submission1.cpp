#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int row =  grid.size();
        int column = grid[0].size();
        vector<vector <int>> dp(row, vector<int> (column, -1));
        dp[0][0] = grid[0][0];
        for (int i=0; i<row; i++) {
            for (int j=0; j<column; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                else if (i-1 < 0) {
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                }
                else if (j-1 < 0) {
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                }
                else {
                    dp[i][j] = min(dp[i-1][j]+grid[i][j], dp[i][j-1]+grid[i][j]);
                }
            }
        }
        return dp[row-1][column-1];
    }
};

