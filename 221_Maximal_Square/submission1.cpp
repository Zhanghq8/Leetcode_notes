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
        vector<vector<int>> sumMatrix = getSum(matrix);
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                int side = min(matrix.size()-i, matrix[i].size()-j);
                for (int k = side; k > 0; k--) {
                    int temp = sumMatrix[i+k][j+k] + sumMatrix[i][j] - sumMatrix[i][j+k] - sumMatrix[i+k][j];
                    if (temp == k * k) {
                        result = max(result, temp);
                    }
                }
            }
        }
        return result;
    }
private:
    vector<vector<int>> getSum(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> result (m+1, vector<int> (n+1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                result[i][j] = result[i-1][j] + result[i][j-1] - result[i-1][j-1] + (matrix[i-1][j-1] - '0');
            }
        }
        return result;
    }
};