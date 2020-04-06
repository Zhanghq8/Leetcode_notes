#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, n + 1);
        dp[0] = 0;
        for (int i = 1; i < n + 1; i++) {
            int sqrtNum = sqrt(i);
            for (int j = 1; j <= sqrtNum; j++) {
                dp[i] = min(dp[i - j * j] + 1, dp[i]);
            }
        }
        return dp.back();
    }
};