#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int result = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp (m+1, vector<int> (n+1, 0));
        for (int i = 1; i<= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (matrix[i-1][j-1] == '0') {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                }
                result = max(result, dp[i][j] * dp[i][j]);
            }
        }
        return result;
    }
};