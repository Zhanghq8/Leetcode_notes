#include <iostream>
#include <string>

using namespace std;

// DP(Bottom-up)

class Solution {
public:
    int fib(int N) {
        vector<int> dp(N+1, 0);
        if (N == 0) {
            return 0;
        }
        dp[0] = 0;
        dp[1] = 1;
        for (int i=2; i<N+1; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[N];
    }
};

