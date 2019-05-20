#include <iostream>
#include <string>

using namespace std;

// Create a new matrix, go through all the rows and columns.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = matrix[0].size();
        vector<vector<int>> result(row, vector<int>(column));
        int flag0 = false;
        for (int i=0; i<row; i++) {
            for (int j=0; j<column; j++) {
                if (matrix[i][j] == 0) {
                    flag0 = true;
                    continue;
                }
            }
            if (flag0 == true) {
                fill(result[i].begin(), result[i].end(), 0);
            }
            else {
                result[i] = matrix[i];
            }
            flag0 = false;
        }
        for (int j=0; j<column; j++) {
            for (int i=0; i<row; i++) {
                if (matrix[i][j] == 0) {
                    flag0 = true;
                    continue;
                }
            }
            if (flag0 == true) {
                for (int i=0; i<row; i++) {
                    result[i][j] = 0;
                }
            }
            flag0 = false;
        }
        matrix = result;
    }
};

