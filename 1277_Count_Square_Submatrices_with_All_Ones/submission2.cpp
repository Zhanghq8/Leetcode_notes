#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size() + 1, vector<int > (matrix[0].size() + 1, 0)); 
        int result = 0;
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 1; j < dp[i].size(); j++) {
                if (matrix[i - 1][j - 1]) {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + matrix[i - 1][j - 1];
                } else {
                    dp[i][j] = 0;
                }
                result += dp[i][j];
            }
        }    
        return result;
    }
};