#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i=0; i<matrix.size(); i++) {
            int left = 0;
            int right = matrix[i].size();
            while (left < right) {
                int mid = left + (right - left)/2;
                if (matrix[i][mid] < target) {
                    left = mid + 1;
                }
                else if (matrix[i][mid] > target) {
                    right = mid;
                }
                else {
                    return true;
                }
            }
        }
        return false;
    }
};

