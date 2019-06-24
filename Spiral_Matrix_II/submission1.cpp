#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        if (n == 0) {
            return result;
        }
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;
        int value = 1;
        cout << n*n+1 << endl;
        while (true) {
            for (int i=left; i <= right; i++) {
                result[top][i] = value;
                value++;
                if (value == n * n + 1) {
                    return result;
                }
            }
            top++;
            for (int j=top; j <= bottom; j++) {
                result[j][right] = value;
                value++;
                if (value == n * n + 1) {
                    return result;
                }
            }
            right--;
            for (int m=right; m >= left; m--) {
                result[bottom][m] = value;
                value++;
                if (value == n * n + 1) {
                    return result;
                }
            }
            bottom--;
            for (int k=bottom; k>= top; k--) {
                result[k][left] = value;
                value++;
                if (value == n * n + 1) {
                    return result;
                }
            }
            left++;
        }
    }
};
