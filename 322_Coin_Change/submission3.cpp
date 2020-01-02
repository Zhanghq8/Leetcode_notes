#include <iostream>
#include <string>

using namespace std;

// DP

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1, vector<int> (amount+1, amount+1));
        for (int i=0; i<coins.size()+1; i++) {
            dp[i][0] = 0;
        }
        for(int i=1; i<coins.size()+1; i++) {
            for (int j=1; j<amount+1; j++) {
                if (coins[i-1] > j) {
                    dp[i][j] = dp[i-1][j];
                }
                else {
                    dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i-1]]+1);
                }
            }
        }
        if (dp[coins.size()][amount] == amount+1) {
            return -1;
        }
        return dp[coins.size()][amount];
    }
};
