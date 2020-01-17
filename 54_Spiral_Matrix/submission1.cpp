#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return {};
        }
        vector<int> result;
        helper(matrix, result, 0, matrix.size(), 0, matrix[0].size(), 0);
        return result;
    }
private:
    void helper(vector<vector<int>>& matrix, vector<int>& result, int rowStart, int rowEnd, int colStart,
               int colEnd, int flag) {
        if (rowStart == rowEnd || colStart == colEnd) {
            return;
        }
        if (flag == 0) {
            for (int i = colStart; i < colEnd; i++) {
                result.push_back(matrix[rowStart][i]);
            }
            return helper(matrix, result, rowStart+1, rowEnd, colStart, colEnd, 1);
        }
        if (flag == 1) {
            for (int i = rowStart; i< rowEnd; i++) {
                result.push_back(matrix[i][colEnd-1]);
            }
            return helper(matrix, result, rowStart, rowEnd, colStart, colEnd-1, 2);
        }
        if (flag == 2) {
            for (int i = colEnd-1; i >= colStart; i--) {
                result.push_back(matrix[rowEnd-1][i]);
            }
            return helper(matrix, result, rowStart, rowEnd-1, colStart, colEnd, 3);
        }
        if (flag == 3) {
            for (int i = rowEnd-1; i >= rowStart; i--) {
                result.push_back(matrix[i][colStart]);
            }
            return helper(matrix, result, rowStart, rowEnd, colStart+1, colEnd, 0);
        }
    }
};