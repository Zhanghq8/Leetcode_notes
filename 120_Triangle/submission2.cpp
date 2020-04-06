#include <iostream>
#include <string>

using namespace std;

// Memo Recursion

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0 || (triangle.size() == 1 && triangle[0].size() == 0)) {
            return 0;
        }
        vector<vector<int>> memo(triangle.size(), vector<int> (triangle[triangle.size()-1].size(), -1));
        return minsum(triangle, memo, 0, 0); 
    }
private:
    int minsum(vector<vector<int>>& triangle, vector<vector<int>>& memo, int i, int j) {
        if (memo[i][j] != -1) {
            return memo[i][j];
        }   
        if (i == triangle.size()-1) {
            return triangle[i][j];
        }
        int left = minsum(triangle, memo, i+1, j) + triangle[i][j];
        int right = minsum(triangle, memo, i+1, j+1) + triangle[i][j];
        memo[i][j] = min(left, right);
        return memo[i][j];
    }
};

