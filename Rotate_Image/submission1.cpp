#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// transpose and reverse each row

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) {
            return;
        }
        for (int i=0; i<matrix.size(); i++) {
            for (int j=i+1; j<matrix[i].size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
