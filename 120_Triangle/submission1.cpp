#include <iostream>
#include <string>

using namespace std;

// Recusion(TLE)

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0 || (triangle.size() == 1 && triangle[0].size() == 0)) {
            return 0;
        }
        return minsum(triangle, 0, 0);
        
    }
    int minsum(vector<vector<int>>& triangle, int i, int j) {
        if (i == triangle.size()-1) {
            return triangle[i][j];
        }
        int left = minsum(triangle, i+1, j) + triangle[i][j];
        int right = minsum(triangle, i+1, j+1) + triangle[i][j];
        return min(left, right);
    }
};

