#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>> sum(matrix.size() + 1, vector<int > (matrix[0].size() + 1, 0)); 
        for (int i = 1; i < sum.size(); i++) {
            for (int j = 1; j < sum[i].size(); j++) {
                sum[i][j] = sum[i - 1][j] + sum [i][j - 1] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }    
        int result = 0;
        int m = sum.size();
        int n = sum[0].size();
        for (int i = 1; i < sum.size(); i++) {
            for (int j = 1; j < sum[i].size(); j++) {
                int maxSide = min(m - i - 1, n - j - 1);
                for (int k = 1; k <= maxSide; k++) {
                    int subSum = sum[i + k][j + k] + sum[i - 1][j - 1] - sum[i - 1][j + k] - sum[i + k][j - 1];
                    if (subSum == (k + 1) * (k + 1)) {
                        result += 1;
                    }
                }
            }
        }
        return result + sum.back().back();
    }
};