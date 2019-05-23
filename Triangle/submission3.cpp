#include <iostream>
#include <string>

using namespace std;

// DP

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0 || (triangle.size() == 1 && triangle[0].size() == 0)) {
            return 0;
        }
        vector<vector<int>> dp(triangle.size(), vector<int> (triangle[triangle.size()-1].size(), -1));
        for (int i=triangle[triangle.size()-1].size()-1; i>=0; i--) {
            dp[triangle.size()-1][i] = triangle[triangle.size()-1][i];
        }
        for (int i=triangle.size()-2; i>=0; i--) {
            for (int j=triangle[i].size()-1; j>=0; j--) {
                dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
            }
        }
        return dp[0][0];
        
    }
};
