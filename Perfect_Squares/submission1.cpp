#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, n+1);
        dp[0] = 0;
        int num = pow(n, 0.5);
        for (int i=1; i<n+1; i++) {
            for (int j=0; j<num; j++) {
                if (i - (j+1)*(j+1) >= 0) {
                    dp[i] = min(dp[i], dp[i-(j+1)*(j+1)] + 1);
                }
            }
        }
        return dp[n];
    }
};