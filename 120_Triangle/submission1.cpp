#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty() || triangle[0].empty()) {
            return 0;
        }
        vector<vector<int>> dp(triangle.size(), vector<int> (triangle[triangle.size() - 1].size(), 0));
        dp[0][0] = triangle[0][0];
        int sum = INT_MAX;
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                if (j == 0) {
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                } else if (j == triangle[i].size() - 1) {
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
                }
                if (i == triangle.size() - 1) {
                    sum = min(sum, dp[i][j]);
                }
            }
        }
        for (int j = 0; j < dp[triangle.size() - 1].size(); j++) {
            sum = min(sum, dp[triangle.size() - 1][j]);
        }
        return sum;
    }
};

