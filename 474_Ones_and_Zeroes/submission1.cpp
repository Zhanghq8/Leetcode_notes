#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size() + 1, vector<vector<int>> (m + 1, vector<int> (n + 1, 0)));
        for (int i = 1; i < strs.size() + 1; i++) {
            int zeros = count(strs[i - 1].begin(), strs[i - 1].end(), '0');
            int ones = count(strs[i - 1].begin(), strs[i - 1].end(), '1');
            for (int j = 0; j < m + 1; j++) {
                for (int k = 0; k < n + 1; k++) {
                    if (zeros <= j && ones <= k) {
                        dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - zeros][k - ones] + 1);
                    } else {
                        dp[i][j][k] = dp[i - 1][j][k];
                    }
                }
            }
        }
        return dp.back().back().back();
    }
};