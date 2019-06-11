#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int row = matrix.size() - 1;
        int column = 0;
        while (true) {
            if (matrix[row][column] > target) {
                row--;
            }
            else if (matrix[row][column] < target) {
                column++;
            }
            else {
                return true;
            }
            if (row < 0 || column >= matrix[0].size()){
                break;
            }
        }
        return false;
    }
};

