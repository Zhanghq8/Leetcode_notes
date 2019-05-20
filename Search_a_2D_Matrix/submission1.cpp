#include <iostream>
#include <string>

using namespace std;

// Two pointers for target row and for target column.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        if (matrix.size() == 1 && matrix[0].size() == 1) {
            return matrix[0][0] == target;
        }
        int row = matrix.size()-1;
        int column = matrix[0].size()-1;
        int top = 0;
        int bottom = row;
        while (top < bottom) {
            int mid = (top+bottom)/2;
            if (matrix[mid][column] == target) {
                return true;
            }
            else if (matrix[mid][column] < target) {
                top = mid+1;
            }
            else {
                bottom = mid;
            }
        }
        int left = 0;
        int right = column;
        while (left < right) {
            int mid = (left+right)/2;
            if (matrix[bottom][mid] == target) {
                return true;
            }
            else if (matrix[bottom][mid] < target) {
                left = mid+1;
            }
            else {
                right = mid;
            }
        }
        return matrix[bottom][right] == target;
    }
};

