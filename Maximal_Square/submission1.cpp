#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int result = 0;
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        vector<vector<int>> dp(matrix.size()+1, vector<int> (matrix[0].size()+1, 0));
        for (int i=1; i<matrix.size()+1; i++) {
            for (int j=1; j<matrix[0].size()+1; j++) {
                if (matrix[i-1][j-1] == '0') {
                    dp[i][j] = 0; 
                }
                else {
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                }
                if (result < dp[i][j]) {
                    result = dp[i][j];
                }
            }
        }
        return result*result;
    }
};