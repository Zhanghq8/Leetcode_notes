#include <iostream>
#include <string>

using namespace std;

// Create two vector to record the rows and columns which have 0 value, go through all the rows and columns.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = matrix[0].size();
        vector<int> row_0(row,1);
        vector<int> column_0(column,1);
        for (int i=0; i<row; i++) {
            for (int j=0; j<column; j++) {
                if (matrix[i][j] == 0) {
                    row_0[i] = 0;
                    column_0[j] = 0;
                    continue;
                }
            }
        }
        for (int i=0; i<row; i++) {
            for (int j=0; j<column; j++) {
                if (row_0[i] == 0 || column_0[j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
