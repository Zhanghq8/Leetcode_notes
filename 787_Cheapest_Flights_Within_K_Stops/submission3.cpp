#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int INF = 1e9;
        vector<vector<int>> dp (K+2, vector<int> (n, INF));
        dp[0][src] = 0;
        for (int i = 1; i <= K+1; i++) {
            dp[i][src] = 0;
            for (auto flight : flights) {
                dp[i][flight[1]] = min(dp[i][flight[1]], dp[i-1][flight[0]] + flight[2]);
            }
        }
        return dp[K+1][dst] == INF ? -1 : dp[K+1][dst];
    }
};