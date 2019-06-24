#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return result;
        }
        int column = matrix[0].size();
        int row = matrix.size();
        int top = 0;
        int bottom = row - 1;
        int left = 0;
        int right = column - 1;
        int size = column * row;
        while (true) {
            for (int i=left; i <= right; i++) {
                result.push_back(matrix[top][i]);
                size--;
                if (size == 0) {
                    return result;
                }
            }
            top++;
            for (int j=top; j <= bottom; j++) {
                result.push_back(matrix[j][right]);
                size--;
                if (size == 0) {
                    return result;
                }
            }
            right--;
            for (int m=right; m >= left; m--) {
                result.push_back(matrix[bottom][m]);
                size--;
                if (size == 0) {
                    return result;
                }
            }
            bottom--;
            for (int n=bottom; n>= top; n--) {
                result.push_back(matrix[n][left]);
                size--;
                if (size == 0) {
                    return result;
                }
            }
            left++;
        }
    }
};

