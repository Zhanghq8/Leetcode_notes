#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// transpose(inverse) and flip each row above index row_size/2

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) {
            return;
        }
        for (int i=0; i<matrix.size()-1; i++) {
            for (int j=0; j<matrix[i].size()-i-1; j++) {
                swap(matrix[i][j], matrix[matrix[i].size()-j-1][matrix[i].size()-i-1]);
            }
        }
        for (int i=0; i<matrix.size()/2; i++) {
            for (int j=0; j<matrix[i].size(); j++) {
                swap(matrix[i][j], matrix[matrix[i].size()-i-1][j]);
            }
        }
    }
};