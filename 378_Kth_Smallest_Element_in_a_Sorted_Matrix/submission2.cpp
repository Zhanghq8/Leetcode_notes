#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix[0][0];
        int right = matrix.back().back();
        while (left < right) {
            int mid = left + (right - left) / 2;
            int total = 0;
            for (int i = 0; i < matrix.size(); i++) {
                total += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if (total >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};