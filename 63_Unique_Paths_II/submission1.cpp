#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) {
            return 0;
        }
        bool flag = false;
        vector<long> dp(obstacleGrid[0].size(), 0);
        for (int i = 0; i < obstacleGrid[0].size(); i++) {
            if (flag || obstacleGrid[0][i]) {
                dp[i] = 0;
                flag = true;
            } else {
                dp[i] = 1;
            }
        }
        for (int i = 1; i < obstacleGrid.size(); i++) {
            for (int j = 0; j < obstacleGrid[i].size(); j++) {
                if (!j) {
                    if (obstacleGrid[i][j]) {
                        dp[j] = 0;
                    } 
                } else {
                    if (obstacleGrid[i][j]) {
                        dp[j] = 0;
                    } else {
                        dp[j] = dp[j - 1] + dp[j];
                    }
                }
            }
        }
        return dp.back();
    }
};