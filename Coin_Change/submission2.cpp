#include <iostream>
#include <string>

using namespace std;

// DP

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int max_num = amount+1;
        vector<int> dp(max_num, max_num);
        dp[0] = 0;
        for (int i=1; i<amount+1; i++) {
            for (int j=0; j<coins.size(); j++) {
                if (i-coins[j] >= 0) {
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
                }
            }
        }
        if (dp[amount] == max_num) {
            return -1;
        }
        else {
            return dp[amount];
        }
    }
};
