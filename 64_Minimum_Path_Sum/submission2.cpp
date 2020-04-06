#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        vector<int> dp(grid[0].size(), 0);
        dp[0] = grid[0][0];
        for (int i = 1; i < dp.size(); i++) {
            dp[i] = dp[i - 1] + grid[0][i];
        }
        for (int i = 1; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (j == 0) {
                    dp[j] = dp[j] + grid[i][j];
                } else {
                    dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
                }
            }
        }
        return dp[grid[0].size() - 1];
    }
};