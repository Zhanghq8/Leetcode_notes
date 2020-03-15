#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return {};
        }
        vector<int> result;
        vector<int> rowMin(matrix.size(), INT_MAX);
        vector<int> columnMax(matrix[0].size(), INT_MIN);
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                rowMin[i] = min(rowMin[i], matrix[i][j]);
            }
        }
        for (int i = 0; i < matrix[0].size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                columnMax[i] = max(columnMax[i], matrix[j][i]);
            }
        }
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == rowMin[i] && matrix[i][j] == columnMax[j]) {
                    result.push_back(matrix[i][j]);
                }
            }
        }
        return result;
    }
};